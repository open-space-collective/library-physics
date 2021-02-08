////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Physics
/// @file           bindings/python/src/OpenSpaceToolkitPhysicsPy/Time/Date.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Physics/Time/Date.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitPhysicsPy_Time_Date         (            pybind11::module&          aModule                                     )
{

    using namespace pybind11 ;

    using ostk::core::types::String ;

    using ostk::physics::time::Date ;

    class_<Date> date(aModule, "Date") ;

    date.def(init<int, int, int>())

        .def(self == self)
        .def(self != self)

        .def("__str__", &(shiftToString<Date>))
        .def("__repr__", +[] (const Date& aDate) -> std::string { return aDate.toString() ; })

        .def("is_defined", &Date::isDefined)

        .def("get_year", &Date::getYear)
        .def("get_month", &Date::getMonth)
        .def("get_day", &Date::getDay)
        .def("to_string", &Date::toString)
        .def("to_string", +[] (const Date& aDate) -> String { return aDate.toString() ; })
        .def("to_string", +[] (const Date& aDate, const Date::Format& aFormat) -> String { return aDate.toString(aFormat) ; })
        .def("set_year", &Date::setYear)
        .def("set_month", &Date::setMonth)
        .def("set_day", &Date::setDay)

        .def_static("undefined", &Date::Undefined)
        .def_static("J2000", &Date::J2000)
        .def_static("GPS_epoch", &Date::GPSEpoch)
        .def_static("unix_epoch", &Date::UnixEpoch)
        .def_static("modified_julian_date_epoch", &Date::ModifiedJulianDateEpoch)
        .def("parse", +[] (const String& aString) -> Date { return Date::Parse(aString) ; })
        .def("parse", +[] (const String& aString, const Date::Format& aFormat) -> Date { return Date::Parse(aString, aFormat) ; })

    ;

    enum_<Date::Format>(date, "Format", pybind11::module_local())

        .value("Undefined", Date::Format::Undefined)
        .value("Standard", Date::Format::Standard)
        .value("STK", Date::Format::STK)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
