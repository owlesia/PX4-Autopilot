############################################################################
#
#   Copyright (c) 2015 PX4 Development Team. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name PX4 nor the names of its contributors may be
#    used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
# OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
############################################################################

cmake_minimum_required(VERSION 3.9)

# common options

enable_language(CXX)

# set(CMAKE_C_COMPILER   "/usr/bin/clang")
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
      -W -Wall -Wextra -Wpedantic \
      -Waggressive-loop-optimizations \
      -Wcast-align -Wcast-qual \
      -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond \
      -Wfloat-equal -Wformat=2 -Wformat-signedness -Wframe-larger-than=32768 \
      -Wlogical-op \
      -Wnull-dereference \
      -Wodr -Wold-style-cast \
      -Wshadow=local -Wshift-overflow=2 -Wstrict-aliasing=2 -Wsuggest-final-methods -Wsuggest-final-types -Wsync-nand \
      -Wtrampolines \
      -Wuseless-cast -Wno-unused-but-set-parameter \
      -Wwrite-strings"
      CACHE INTERNAL ""
  )
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
      -Weverything \
      -Wno-class-varargs -Wno-padded \
      -Wc++17-compat \
      -Wno-c++98-compat -Wno-c++98-compat-pedantic"
      # -Wno-c++14-extensions
      # -Wno-c++17-extensions
      # -Wno-switch-enum -Wno-unused-macros
      CACHE INTERNAL ""
  )
endif()

px4_add_module(
	MODULE examples__battery_soc
	MAIN battery_soc
	COMPILE_FLAGS
	SRCS
		battery_soc.cpp
		src/utils.cpp
		src/baseLayer.cpp
		src/layers/activation.cpp
		src/layers/conv1d.cpp
		src/layers/conv2d.cpp
		src/layers/dense.cpp
		src/layers/elu.cpp
		src/layers/embedding.cpp
		src/layers/flatten.cpp
		src/layers/lstm.cpp
		src/layers/locally1d.cpp
		src/layers/locally2d.cpp
		src/layers/maxPooling2d.cpp
		src/layers/batchNormalization.cpp
		src/model.cpp
		src/tensor.cpp
	DEPENDS
	)
