/*
 * Copyright 2013-2017, Corvusoft Ltd, All Rights Reserved.
 */

#ifndef _CORVUSOFT_RESTLESS_DETAIL_SESSION_IMPL_H
#define _CORVUSOFT_RESTLESS_DETAIL_SESSION_IMPL_H 1

//System Includes
#include <map>
#include <memory>
#include <string>
#include <functional>
#include <system_error>

//Project Includes

//External Includes
#include <corvusoft/protocol/protocol.hpp>

//System Namespaces

//Project Namespaces

//External Namespaces

namespace corvusoft
{
    //Forward Declarations
    namespace core
    {
        class RunLoop;
    }
    
    namespace network
    {
        class Adaptor;
    }
    
    namespace protocol
    {
        class Protocol;
    }
    
    namespace restless
    {
        //Forward Declarations
        class Settings;
        
        namespace detail
        {
            //Forward Declarations
            
            struct SessionImpl
            {
                std::shared_ptr< Settings > settings = nullptr;
                
                std::shared_ptr< core::RunLoop > runloop = nullptr;
                
                std::shared_ptr< network::Adaptor > adaptor = nullptr;
                
                std::shared_ptr< protocol::Protocol > protocol = nullptr;
                
                std::multimap< std::string, std::string > default_headers { };
                
                std::multimap< std::string, const std::function< std::string ( void ) > > computed_headers { };
                
                std::function< std::error_code ( const int, const std::string ) > log_handler = nullptr;
                
                std::function< std::error_code ( const std::shared_ptr< const Request > ) > connection_timeout_handler = nullptr;
                
                std::function< std::error_code ( const std::shared_ptr< const Request >, const std::shared_ptr< const Response >, const std::error_code ) > error_handler = nullptr;
                
                const std::function< void ( const std::shared_ptr< network::Adaptor > ) > open_handler = [ ]( const auto adaptor )
                {
                
                };
                
                const std::function< void ( const std::shared_ptr< network::Adaptor > ) > close_handler = [ ]( const auto adaptor )
                {
                    //runloop->cancel( "adaptor key" );
                };
                
                const std::function< void ( const std::shared_ptr< network::Adaptor > ) > message_handler = [ ]( const auto adaptor )
                {
                    //response_handler( respons );
                };
                
                const std::function< void ( const std::shared_ptr< network::Adaptor >, const std::error_code ) > fault_handler = [ ]( const auto adaptor, const auto error )
                {
                    //log error then
                    //if error code == connection timeout: connection_timeout_handler( );
                    //else fault_handler( );
                };
            };
        }
    }
}

#endif  /* _CORVUSOFT_RESTLESS_DETAIL_SESSION_IMPL_H */
