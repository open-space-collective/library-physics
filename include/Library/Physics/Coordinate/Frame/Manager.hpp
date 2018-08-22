////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Physics
/// @file           Library/Physics/Coordinate/Frame/Manager.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Physics_Coordinate_Frame_Manager__
#define __Library_Physics_Coordinate_Frame_Manager__

#include <Library/Physics/Coordinate/Frame.hpp>
#include <Library/Physics/Time/Instant.hpp>

#include <Library/Core/Containers/Map.hpp>
#include <Library/Core/Types/String.hpp>
#include <Library/Core/Types/Shared.hpp>

#include <mutex>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace physics
{
namespace coord
{
namespace frame
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Shared ;
using library::core::types::String ;
using library::core::ctnr::Map ;

using library::physics::time::Instant ;
using library::physics::coord::Frame ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Reference frame manager (thread-safe)

class Manager
{

    public:

                                Manager                                     ( ) ;

        bool                    hasFrameWithName                            (   const   String&                     aFrameName                                  ) const ;

        Shared<const Frame>     accessFrameWithName                         (   const   String&                     aFrameName                                  ) const ;

        void                    addFrame                                    (   const   Frame&                      aFrame                                      ) ;

        void                    addFrame                                    (   const   Shared<const Frame>&        aFrameSPtr                                  ) ;

        void                    removeFrameWithName                         (   const   String&                     aFrameName                                  ) ;

    private:

        Map<String, Shared<const Frame>> frameMap_ ;

        mutable std::mutex      mutex_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////