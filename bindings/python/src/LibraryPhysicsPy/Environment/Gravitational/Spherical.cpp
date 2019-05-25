////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library ▸ Physics
/// @file           LibraryPhysicsPy/Environment/Gravitational/Spherical.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Physics/Environment/Gravitational/Spherical.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryPhysicsPy_Environment_Gravitational_Spherical ( )
{

    using namespace boost::python ;

    using library::physics::units::Derived ;
    using library::physics::environment::gravitational::Spherical ;

    scope in_Spherical = class_<Spherical>("Spherical", init<const Derived&>())

        .def("getFieldValueAt", &Spherical::getFieldValueAt)

    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////