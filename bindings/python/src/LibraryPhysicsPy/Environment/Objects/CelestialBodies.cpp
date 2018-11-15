////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           LibraryPhysicsPy/Environment/Objects/CelestialBodies.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <LibraryPhysicsPy/Environment/Objects/CelestialBodies/Earth.cpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryPhysicsPy_Environment_Objects_CelestialBodies ( )
{
    
    boost::python::object module(boost::python::handle<>(boost::python::borrowed(PyImport_AddModule("Library.Physics.Environment.Objects.CelestialBodies")))) ;
    
    boost::python::scope().attr("CelestialBodies") = module ;
    
    boost::python::scope scope = module ;
    
    LibraryPhysicsPy_Environment_Objects_CelestialBodies_Earth() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////