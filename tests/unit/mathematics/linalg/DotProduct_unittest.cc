/*
 * Copyright (c) 2014, Shogun Toolbox Foundation
 * All rights reserved.
 *
 * Written (W) 2014 Sunil K. Mahendrakar
 * Written (W) 2014 Soumyajit De
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:

 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <shogun/lib/config.h>

#include <shogun/mathematics/linalg/linalg.h>

#ifdef HAVE_DEFAULT
#include <shogun/lib/SGVector.h>
#include <gtest/gtest.h>

#ifdef HAVE_EIGEN3
#include <shogun/mathematics/eigen3.h>

using namespace Eigen;
#endif // HAVE_EIGEN3

using namespace shogun;

TEST(DotProduct, SGVector_default_backend)
{
    const index_t size=10;
    SGVector<float64_t> a(size), b(size);
    a.set_const(1.0);
    b.set_const(2.0);

    EXPECT_NEAR(linalg::dot(a, b), 20.0, 1E-15);
}

#ifdef HAVE_EIGEN3
TEST(DotProduct, Eigen3_Vector_dynamic_size)
{
	index_t size=10;
	VectorXd a=VectorXd::Constant(size, 1);
	VectorXd b=VectorXd::Constant(size, 2);

    EXPECT_NEAR(linalg::dot(a, b), 20.0, 1E-15);
}

TEST(DotProduct, Eigen3_Vector_fixed_size)
{
	Vector3d a=Vector3d::Constant(1);
	Vector3d b=Vector3d::Constant(2);

    EXPECT_NEAR(linalg::dot(a, b), 6.0, 1E-15);
}
#endif // HAVE_EIGEN3

#endif // HAVE_DEFAULT
