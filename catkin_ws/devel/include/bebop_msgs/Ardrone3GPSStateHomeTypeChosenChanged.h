// Generated by gencpp from file bebop_msgs/Ardrone3GPSStateHomeTypeChosenChanged.msg
// DO NOT EDIT!


#ifndef BEBOP_MSGS_MESSAGE_ARDRONE3GPSSTATEHOMETYPECHOSENCHANGED_H
#define BEBOP_MSGS_MESSAGE_ARDRONE3GPSSTATEHOMETYPECHOSENCHANGED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace bebop_msgs
{
template <class ContainerAllocator>
struct Ardrone3GPSStateHomeTypeChosenChanged_
{
  typedef Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> Type;

  Ardrone3GPSStateHomeTypeChosenChanged_()
    : header()
    , type(0)  {
    }
  Ardrone3GPSStateHomeTypeChosenChanged_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , type(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _type_type;
  _type_type type;



  enum {
    type_TAKEOFF = 0u,
    type_PILOT = 1u,
    type_FIRST_FIX = 2u,
    type_FOLLOWEE = 3u,
  };


  typedef boost::shared_ptr< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> const> ConstPtr;

}; // struct Ardrone3GPSStateHomeTypeChosenChanged_

typedef ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<std::allocator<void> > Ardrone3GPSStateHomeTypeChosenChanged;

typedef boost::shared_ptr< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged > Ardrone3GPSStateHomeTypeChosenChangedPtr;
typedef boost::shared_ptr< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged const> Ardrone3GPSStateHomeTypeChosenChangedConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace bebop_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'bebop_msgs': ['/home/nim/catkin_ws/src/bebop_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "399148a783deb6496d223249b9e3e911";
  }

  static const char* value(const ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x399148a783deb649ULL;
  static const uint64_t static_value2 = 0x6d223249b9e3e911ULL;
};

template<class ContainerAllocator>
struct DataType< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bebop_msgs/Ardrone3GPSStateHomeTypeChosenChanged";
  }

  static const char* value(const ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Ardrone3GPSStateHomeTypeChosenChanged\n\
# auto-generated from up stream XML files at\n\
#   github.com/Parrot-Developers/libARCommands/tree/master/Xml\n\
# To check upstream commit hash, refer to last_build_info file\n\
# Do not modify this file by hand. Check scripts/meta folder for generator files.\n\
#\n\
# SDK Comment: Home type.\\n This choice is made by the drone, according to the [PreferredHomeType](#1-24-4) and the [HomeTypeAvailability](#1-31-1). The drone will choose the type matching with the user preference only if this type is available. If not, it will chose a type in this order:\\n FOLLOWEE ; TAKEOFF ; PILOT ; FIRST_FIX\n\
\n\
Header header\n\
\n\
# The type of the return home chosen\n\
uint8 type_TAKEOFF=0  # The drone will return to the take off position\n\
uint8 type_PILOT=1  # The drone will return to the pilot position In this case, the drone will use the position given by ARDrone3-SendControllerGPS\n\
uint8 type_FIRST_FIX=2  # The drone has not enough information, it will return to the first GPS fix\n\
uint8 type_FOLLOWEE=3  # The drone will return to the target of the current (or last) follow me In this case, the drone will use the position of the target of the followMe (given by ControllerInfo-GPS)\n\
uint8 type\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.type);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Ardrone3GPSStateHomeTypeChosenChanged_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::bebop_msgs::Ardrone3GPSStateHomeTypeChosenChanged_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "type: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.type);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEBOP_MSGS_MESSAGE_ARDRONE3GPSSTATEHOMETYPECHOSENCHANGED_H
