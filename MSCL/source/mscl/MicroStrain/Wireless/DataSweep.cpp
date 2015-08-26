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

#include "DataSweep.h"

namespace mscl
{
	DataSweep::DataSweep():
		m_timestamp(0),
		m_tick(0),
		m_sampleRate(SampleRate::rateType_hertz, 1),
		m_nodeAddress(0),
		m_samplingMode(samplingType_SyncSampling),
		m_nodeRssi(0),
		m_baseRssi(0),
		m_frequency(WirelessTypes::freq_unknown)
	{
	}

	Timestamp DataSweep::timestamp() const
	{
		return m_timestamp;
	}

	void DataSweep::timestamp(const Timestamp& time)
	{
		m_timestamp = time;
	}

	uint64 DataSweep::nanoseconds() const
	{
		return m_timestamp.nanoseconds();
	}

	uint32 DataSweep::tick() const
	{
		return m_tick;
	}

	void DataSweep::tick(uint32 tick)
	{
		m_tick = tick;
	}

	SampleRate DataSweep::sampleRate() const
	{
		return m_sampleRate;
	}

	void DataSweep::sampleRate(SampleRate rate)
	{
		m_sampleRate = rate;
	}

	NodeAddress DataSweep::nodeAddress() const
	{
		return m_nodeAddress;
	}

	void DataSweep::nodeAddress(NodeAddress address)
	{
		m_nodeAddress = address;
	}

	const ChannelData& DataSweep::data() const
	{
		return m_data;
	}

	void DataSweep::data(ChannelData data)
	{
		m_data = data;
	}

	DataSweep::SamplingType DataSweep::samplingType() const
	{
		return m_samplingMode;
	}

	void DataSweep::samplingType(DataSweep::SamplingType type)
	{
		m_samplingMode = type;
	}

	int16 DataSweep::nodeRssi() const
	{
		return m_nodeRssi;
	}

	void DataSweep::nodeRssi(int16 rssi)
	{
		m_nodeRssi = rssi;
	}

	int16 DataSweep::baseRssi() const
	{
		return m_baseRssi;
	}

	void DataSweep::baseRssi(int16 rssi)
	{
		m_baseRssi = rssi;
	}

	WirelessTypes::Frequency DataSweep::frequency() const
	{
		return m_frequency;
	}

	void DataSweep::frequency(WirelessTypes::Frequency freq)
	{
		m_frequency = freq;
	}
}