////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Coordinate/Position.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Physics_Coordinate_Position__
#define __Library_Physics_Coordinate_Position__

#include <Library/Mathematics/Objects/Vector.hpp>

#include <Library/Core/Types/String.hpp>
#include <Library/Core/Types/Shared.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace physics
{
namespace coord
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Shared ;
using library::core::types::String ;

using library::math::obj::Vector3d ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Frame ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Position

class Position
{

    public:

                                Position                                    (   const   Vector3d&                   aCoordinateSet, // add unit?
                                                                                const   Shared<const Frame>&        aFrame                                      ) ;

        bool                    operator ==                                 (   const   Position&                   aPosition                                   ) const ;
        
        bool                    operator !=                                 (   const   Position&                   aPosition                                   ) const ;

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Position&                   aPosition                                   ) ;

        bool                    isDefined                                   ( ) const ;

        const Vector3d&         accessCoordinates                           ( ) const ;

        const Frame&            accessFrame                                 ( ) const ;

        String                  toString                                    ( ) const ;

        static Position         Undefined                                   ( ) ;

    private:

        Vector3d                coordinates_ ; // [m]

        Shared<const Frame>     frameSPtr_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////