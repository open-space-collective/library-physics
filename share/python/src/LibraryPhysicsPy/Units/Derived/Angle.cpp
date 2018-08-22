////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           LibraryPhysicsPy/Units/Derived/Angle.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Physics/Units/Derived/Angle.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS (LibraryPhysicsPy_Units_Angle_toString_overloads, library::physics::units::Angle::toString, 0, 1)

inline void                     LibraryPhysicsPy_Units_Derived_Angle        ( )
{

    using namespace boost::python ;

    using library::core::types::Real ;

    using library::physics::units::Angle ;

    scope in_Angle = class_<Angle>("Angle", init<Real, Angle::Unit>())

        .def(self == self)
        .def(self != self)

        .def(self + self)
        .def(self - self)

        .def(self * other<Real>())
        .def(self / other<Real>())

        .def(self += self)
        .def(self -= self)

        .def(self *= other<Real>())
        .def(self /= other<Real>())

        .def(self_ns::str(self_ns::self))

        .def("__repr__", +[] (const Angle& anAngle) -> std::string { return anAngle.toString() ; })

        .def("isDefined", &Angle::isDefined)
        .def("isZero", &Angle::isZero)

        .def("getUnit", &Angle::getUnit)
        .def("inUnit", &Angle::in)
        .def("inRadians", +[] (const Angle& anAngle) -> Real { return anAngle.inRadians() ; })
        .def("inDegrees", +[] (const Angle& anAngle) -> Real { return anAngle.inDegrees() ; })
        .def("inArcminutes", +[] (const Angle& anAngle) -> Real { return anAngle.inArcminutes() ; })
        .def("inArcseconds", +[] (const Angle& anAngle) -> Real { return anAngle.inArcseconds() ; })
        .def("inRevolutions", &Angle::inRevolutions)
        .def("toString", &Angle::toString, LibraryPhysicsPy_Units_Angle_toString_overloads())
        
        .def("Undefined", &Angle::Undefined).staticmethod("Undefined")
        .def("Radians", &Angle::Radians).staticmethod("Radians")
        .def("Degrees", &Angle::Degrees).staticmethod("Degrees")
        .def("Arcminutes", &Angle::Arcminutes).staticmethod("Arcminutes")
        .def("Arcseconds", &Angle::Arcseconds).staticmethod("Arcseconds")
        .def("Revolutions", &Angle::Revolutions).staticmethod("Revolutions")
        // .def("Parse", &Angle::Parse).staticmethod("Parse")
        .def("StringFromUnit", &Angle::StringFromUnit).staticmethod("StringFromUnit")
        .def("SymbolFromUnit", &Angle::SymbolFromUnit).staticmethod("SymbolFromUnit")

    ;

    enum_<Angle::Unit>("Unit")

        .value("Undefined", Angle::Unit::Undefined)
        .value("Radian", Angle::Unit::Radian)
        .value("Degree", Angle::Unit::Degree)
        .value("Arcminute", Angle::Unit::Arcminute)
        .value("Arcsecond", Angle::Unit::Arcsecond)
        .value("Revolution", Angle::Unit::Revolution)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////