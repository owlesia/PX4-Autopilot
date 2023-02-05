/****************************************************************************
 *
 *   Copyright (C) 2015 Mark Charlebois. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file battery_soc_posix.cpp
 *
 * @author Thomas Gubler <thomasgubler@gmail.com>
 * @author Mark Charlebois <mcharleb@gmail.com>
 */

#include <px4_platform_common/log.h>
#include <px4_platform_common/app.h>
#include <px4_platform_common/tasks.h>
#include <stdio.h>
#include <string.h>
#include <sched.h>

#include "src/model.h"

using keras2cpp::Model;
using keras2cpp::Tensor;

extern "C" __EXPORT int battery_soc_main(int argc, char *argv[]);
int battery_soc_main(int argc, char *argv[])
{
	printf("Starting inference\n");

	printf("Initializing model\n");
	auto model = Model::load("/Users/olesiaelfimova/Projects/PX4-Autopilot/src/examples/battery_soc/example.model");

	printf("Creating a 1D Tensor on length 10 for input data\n");
	Tensor in{3};
	in.data_ = {4.05296, -5.4504, 21.51979};

	// PROBLEM
	printf("Running prediction\n");
	Tensor out = model(in);
	out.print();

	printf("Goodbye\n");
	return 0;
}
