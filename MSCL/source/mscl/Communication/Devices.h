/*******************************************************************************
Copyright(c) 2015-2016 LORD Corporation. All rights reserved.

MIT Licensed. See the included LICENSE.txt for a copy of the full MIT License.
*******************************************************************************/

#pragma once

#include <string>
#include <map>

namespace mscl
{
    //API Title: Devices

    //API Class: DeviceInfo
    //    Contains information on an attached device
    class DeviceInfo
    {
    public:
        //Constructor: DeviceInfo
        //    Creates a DeviceInfo object
        DeviceInfo();

        //Constructor: DeviceInfo
        //    Creates a DeviceInfo object with the given parameters
        //
        //Parameters:
        //    description - The description of the device
        //    serial - The serial address that is issued for this device
        DeviceInfo(std::string description, std::string serial);

    private:
        //Variable: m_description
        //    The description of the device
        std::string m_description;

        //Variable: m_serial
        //    The serial address that is issued for this device
        std::string m_serial;

    public:
        //API Function: description
        //    Gets the description for the device
        //
        //Returns:
        //    The description of the device
        std::string description() const;

        //API Function: serial
        //    Gets the serial address for the device
        //
        //Returns:
        //    The serial number of the device
        std::string serial() const;
    };
    

    //API Class: Devices
    //    Contains helper functions for accessing attached devices
    class Devices
    {
    private:
        //API Enums: DeviceType
        //    TYPE_ALL            - 0 - All Devices
        //    TYPE_BASESTATION    - 1 - Device of a BaseStation type
        //    TYPE_INERTIALDEVICE - 2 - Device of an InertialDevice type
        enum DeviceType
        {
            TYPE_ALL                = 0,
            TYPE_BASESTATION        = 1,
            TYPE_INERTIALDEVICE        = 2
        };

    public:
        //API Typedef: DeviceList
        //    Typedef for a map of string COM ports to <DeviceInfo> objects detailing the information about each device
        typedef std::map<std::string, DeviceInfo> DeviceList;

    private:
        Devices();                            //default constructor disabled
        Devices(const Devices&);            //copy constructor disabled
        Devices& operator=(const Devices&);    //assignment operator disabled

    public:
        //API Function: listBaseStations
        //    Gets a list of all the attached (USB) BaseStations.
        //    Note that this is solely going by listed devices that use our driver, so this may pick up similar devices that are not BaseStations.
        //
        //Returns:
        //    A <DeviceList> representing the COM ports that were found that match MicroStrain BaseStations. 
        //    If none were found, the list will be empty.
        static DeviceList listBaseStations();

        //API Function: listInertialDevices
        //    Gets a list of all the attached (USB) InertialDevices.
        //
        //Returns:
        //    A <DeviceList> representing the COM ports that were found that match MicroStrain InertialDevices. 
        //    If none were found, the list will be empty.
        static DeviceList listInertialDevices();

        //API Function: listPorts
        //    Gets a simple list of all serial ports and their availability. This function does not tell you which device is on which port, but can be useful for listing actual serial ports.
        //
        //Returns:
        //    A <DeviceList> representing the ports that were found and their availability. 
        //    If none were found, the list will be empty.
        static DeviceList listPorts();

    private:
        //Function: listDevices
        //    Gets a list of attached devices that match the given DeviceType
        //
        //Parameters:
        //    devType - The type of device to list
        static DeviceList listDevices(DeviceType devType);

#ifdef WIN32
        //Function: matchesDevice
        //    Checks whether a given string found from WMI matches the given device
        //
        //Parameters:
        //    pnpID - The WMI PNPDeviceID to match
        //    name - The WMI Name to match
        //    devType - The <DeviceType> to check for
        //
        //Returns:
        //    true if the string matches the given <DeviceType>, false otherwise
        static bool matchesDevice(const std::string& pnpID, const std::string& name, DeviceType devType);
#else
        //Function: matchesDevice
        //    Checks whether the given information, found from searching files in linux, matches the given device
        //
        //Parameters:
        //    manufacturer - The manufacturer of the device
        //    vendorId - The vendor id of the device
        //    devType - The <DeviceType> to check for
        //
        //Returns:
        //    true if the string matches the given <DeviceType>, false otherwise
        static bool matchesDevice(const std::string& manufacturer, const std::string& vendorId, DeviceType devType);
        
        //Function: getDeviceInfo
        //    Gets information about the attached device
        //
        //Parameters:
        //    devicePath - The device path in the directory/form of "/sys/bus/___/devices/___"
        //    serial - An output parameter that holds the resulting serial of the device
        //    manufacturer - An output parameter that holds the resulting manufacturer of the device
        //    vendorId - An output parameter that holds the resulting vendor ID of the device
        //
        //Returns:
        //    true if successfully find the device info, false otherwise
        static bool getDeviceInfo(const std::string& devicePath, std::string& serial, std::string& manufacturer, std::string& vendorId);
#endif
    };

}