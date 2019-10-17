// Generated by gencpp from file bebop_msgs/CommonFlightPlanStateAvailabilityStateChanged.msg
// DO NOT EDIT!


#ifndef BEBOP_MSGS_MESSAGE_COMMONFLIGHTPLANSTATEAVAILABILITYSTATECHANGED_H
#define BEBOP_MSGS_MESSAGE_COMMONFLIGHTPLANSTATEAVAILABILITYSTATECHANGED_H


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
struct CommonFlightPlanStateAvailabilityStateChanged_
{
  typedef CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> Type;

  CommonFlightPlanStateAvailabilityStateChanged_()
    : header()
    , AvailabilityState(0)  {
    }
  CommonFlightPlanStateAvailabilityStateChanged_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , AvailabilityState(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _AvailabilityState_type;
  _AvailabilityState_type AvailabilityState;





  typedef boost::shared_ptr< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> const> ConstPtr;

}; // struct CommonFlightPlanStateAvailabilityStateChanged_

typedef ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<std::allocator<void> > CommonFlightPlanStateAvailabilityStateChanged;

typedef boost::shared_ptr< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged > CommonFlightPlanStateAvailabilityStateChangedPtr;
typedef boost::shared_ptr< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged const> CommonFlightPlanStateAvailabilityStateChangedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b47d280696828874e694f8c4035109de";
  }

  static const char* value(const ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb47d280696828874ULL;
  static const uint64_t static_value2 = 0xe694f8c4035109deULL;
};

template<class ContainerAllocator>
struct DataType< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bebop_msgs/CommonFlightPlanStateAvailabilityStateChanged";
  }

  static const char* value(const ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# CommonFlightPlanStateAvailabilityStateChanged\n\
# auto-generated from up stream XML files at\n\
#   github.com/Parrot-Developers/libARCommands/tree/master/Xml\n\
# To check upstream commit hash, refer to last_build_info file\n\
# Do not modify this file by hand. Check scripts/meta folder for generator files.\n\
#\n\
# SDK Comment: FlightPlan availability.\\n Availability is linked to GPS fix, magnetometer calibration, sensor states...\n\
\n\
Header header\n\
\n\
# Running a flightPlan file is available (1 running a flightPlan file is available, otherwise 0)\n\
uint8 AvailabilityState\n\
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

  static const char* value(const ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.AvailabilityState);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CommonFlightPlanStateAvailabilityStateChanged_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::bebop_msgs::CommonFlightPlanStateAvailabilityStateChanged_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "AvailabilityState: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.AvailabilityState);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BEBOP_MSGS_MESSAGE_COMMONFLIGHTPLANSTATEAVAILABILITYSTATECHANGED_H
