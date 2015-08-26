/*****************************************************************************
Copyright(c) 2015 LORD Corporation. All rights reserved.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the included
LICENSE.txt file for a copy of the full GNU General Public License.
*****************************************************************************/
#include "stdafx.h"

#include "mscl/Exceptions.h"
#include "HclSmartBearing_RawPacket.h"
#include "mscl/MicroStrain/Wireless/ChannelMask.h"
#include "mscl/MicroStrain/SampleUtils.h"
#include "mscl/MicroStrain/Vector.h"
#include "mscl/TimeSpan.h"
#include "mscl/Types.h"

namespace mscl
{

	HclSmartBearing_RawPacket::HclSmartBearing_RawPacket(const WirelessPacket& packet)
	{
		//construct the data packet from the wireless packet passed in
		m_nodeAddress		= packet.nodeAddress();
		m_deliveryStopFlags = packet.deliveryStopFlags();
		m_type				= packet.type();
		m_nodeRSSI			= packet.nodeRSSI();
		m_baseRSSI			= packet.baseRSSI();
		m_frequency			= packet.frequency();
		m_payload			= packet.payload();
		m_payloadOffsetChannelData = 0;	//not used for these packets

		//parse the data sweeps in the packet
		parseSweeps();
	}

	void HclSmartBearing_RawPacket::parseSweeps()
	{
		//read the app id
		RawPacketId appId = static_cast<RawPacketId>(m_payload.read_uint8(PAYLOAD_OFFSET_APP_ID));

		switch(appId)
		{
			case rawPacket_baseBoard:
				parseSweeps_baseBoard();
				break;

			case rawPacket_strainBoard:
				//TODO: parse the strain board packet
				break;

			case rawPacket_inertialBoard:
				//TODO: parse the inertial board packet
				break;

			default:
				//invalid app id
				break;
		}
	}

	void HclSmartBearing_RawPacket::parseSweeps_baseBoard()
	{
		typedef WirelessChannel WC;
		static const uint16 PAYLOAD_OFFSET_MAG_CONVERSION = 13;

		//read the values from the payload
		uint8 sensorErrorMask	= m_payload.read_uint8(PAYLOAD_OFFSET_ERROR_MASK);
		uint8 sampleRate		= m_payload.read_uint8(PAYLOAD_OFFSET_SAMPLE_RATE);
		uint16 tick				= m_payload.read_uint16(PAYLOAD_OFFSET_TICK);
		uint64 timestampSeconds	= m_payload.read_uint32(PAYLOAD_OFFSET_TS_SEC);		//the timestamp (UTC) seconds part
		uint64 timestampNanos	= m_payload.read_uint32(PAYLOAD_OFFSET_TS_NANOSEC);	//the timestamp (UTC) nanoseconds part
		m_magConversionVal		= static_cast<float>(m_payload.read_uint16(PAYLOAD_OFFSET_MAG_CONVERSION));

		//build the full nanosecond resolution timestamp from the seconds and nanoseconds values read above
		uint64 realTimestamp = (timestampSeconds * TimeSpan::NANOSECONDS_PER_SECOND) + timestampNanos;

		//create a SampleRate object from the sampleRate byte
		SampleRate currentRate = SampleUtils::convertToSampleRate(sampleRate);

		//build the single sweep
		DataSweep sweep;
		sweep.samplingType(DataSweep::samplingType_SyncSampling);
		sweep.frequency(m_frequency);
		sweep.tick(tick);
		sweep.nodeAddress(m_nodeAddress);
		sweep.sampleRate(currentRate);
		sweep.timestamp(Timestamp(realTimestamp));
		sweep.nodeRssi(m_nodeRSSI);
		sweep.baseRssi(m_baseRSSI);

		static const uint16 DATA_START = 15;

		ChannelData chData;
		chData.reserve(28);
		chData.emplace_back(WC::channel_error_code, 0, valueType_uint8, anyType(sensorErrorMask));	//Error Mask (not actually in payload)
		chData.emplace_back(WC::channel_hcl_rawBase_mag1_x, 1, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 0)));	//Mag 1 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag1_y, 2, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 2)));	//Mag 1 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag1_z, 3, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 4)));	//Mag 1 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_mag2_x, 4, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 6)));	//Mag 2 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag2_y, 5, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 8)));	//Mag 2 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag2_z, 6, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 10)));	//Mag 2 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_mag3_x, 7, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 12)));	//Mag 3 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag3_y, 8, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 14)));	//Mag 3 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag3_z, 9, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 16)));	//Mag 3 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_mag4_x, 10, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 18)));	//Mag 4 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag4_y, 11, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 20)));	//Mag 4 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag4_z, 12, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 22)));	//Mag 4 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_mag5_x, 13, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 24)));	//Mag 5 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag5_y, 14, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 26)));	//Mag 5 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag5_z, 15, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 28)));	//Mag 5 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_mag6_x, 16, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 30)));	//Mag 6 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag6_y, 17, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 32)));	//Mag 6 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag6_z, 18, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 34)));	//Mag 6 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_mag7_x, 19, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 36)));	//Mag 7 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag7_y, 20, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 38)));	//Mag 7 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag7_z, 21, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 40)));	//Mag 7 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_mag8_x, 22, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 42)));	//Mag 8 - X
		chData.emplace_back(WC::channel_hcl_rawBase_mag8_y, 23, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 44)));	//Mag 8 - Y
		chData.emplace_back(WC::channel_hcl_rawBase_mag8_z, 24, valueType_float, getMagChValue(m_payload.read_uint16(DATA_START + 46)));	//Mag 8 - Z
		chData.emplace_back(WC::channel_hcl_rawBase_gyro_x, 25, valueType_float, anyType(m_payload.read_float(DATA_START + 48)));			//Gyro - X
		chData.emplace_back(WC::channel_hcl_rawBase_gyro_y, 26, valueType_float, anyType(m_payload.read_float(DATA_START + 52)));			//Gyro - Y
		chData.emplace_back(WC::channel_hcl_rawBase_gyro_z, 27, valueType_float, anyType(m_payload.read_float(DATA_START + 56)));			//Gyro - Z

		//add all of the channel data to the sweep
		sweep.data(chData);

		//add the sweep to the container of sweeps
		addSweep(sweep);
	}

	anyType HclSmartBearing_RawPacket::getMagChValue(uint16 packetVal)
	{
		return anyType(static_cast<float>(packetVal) / m_magConversionVal);
	}

	bool HclSmartBearing_RawPacket::integrityCheck(const WirelessPacket& packet)
	{
		//verify the delivery stop flags are what we expected
		if(!packet.deliveryStopFlags().pc)
		{
			//packet not intended for the PC
			return false;
		}

		//verify the packet type is correct
		if(packet.type() != packetType_HclSmartBearing_Raw)
		{
			//packet is not a Sync Sampling packet
			return false;
		}

		const WirelessPacket::Payload& payload = packet.payload();

		//verify the payload size
		if(payload.size() < 4)
		{
			//each of these packets has at least the 4 main bytes in its header
			return false;
		}

		//read the app id
		RawPacketId appId = static_cast<RawPacketId>(payload.read_uint8(PAYLOAD_OFFSET_APP_ID));

		switch(appId)
		{
			case rawPacket_baseBoard:
				return integrityCheck_baseBoard(payload);

			case rawPacket_strainBoard:
				//TODO: parse the strain board packet
				return false;

			case rawPacket_inertialBoard:
				//TODO: parse the inertial board packet
				return false;

			default:
				//invalid app id
				return false;
		}
	}

	bool HclSmartBearing_RawPacket::integrityCheck_baseBoard(const WirelessPacket::Payload& payload)
	{
		//check payload size is exactly correct
		if(payload.size() != 75)
		{
			return false;
		}

		//packet looks valid
		return true;
	}

	UniqueWirelessPacketId HclSmartBearing_RawPacket::getUniqueId(const WirelessPacket& packet)
	{
		//return the tick value
		return packet.payload().read_uint16(PAYLOAD_OFFSET_TICK);
	}
}