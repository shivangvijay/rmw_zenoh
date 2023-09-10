// Copyright 2023 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SRC__DETAIL__RMW_DATA_TYPES_HPP
#define SRC__DETAIL__RMW_DATA_TYPES_HPP

#include <condition_variable>
#include <mutex>

#include "rmw/rmw.h"

#include "TypeSupport.hpp"

#include "zenoh.h"

/// Structs for various type erased data fields.
///==============================================================================
struct rmw_publisher_data_t
{
  // An owned publisher.
  z_owned_publisher_t pub;

  // Type support fields
  const void * type_support_impl;
  const char * typesupport_identifier;
  TypeSupport * type_support;

  // Context for memory allocation for messages.
  rmw_context_t * context;
};

///==============================================================================
struct rmw_wait_set_data_t
{
  std::condition_variable condition;
  std::mutex condition_mutex;
};

#endif  // SRC__DETAIL__RMW_DATA_TYPES_HPP
