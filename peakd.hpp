// Copyright 2025, MS-Cheminformatics LLC
// Licensed under the MIT License:
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
/**************************************************************************
** Copyright (C) 2010-2024 Toshinobu Hondo, Ph.D.
** Copyright (C) 2013-2024 MS-Cheminformatics LLC, Toin, Mie Japan
*
** Contact: toshi.hondo@qtplatz.com
**
** Commercial Usage
**
** Licensees holding valid MS-Cheminfomatics commercial licenses may use this file in
** accordance with the MS-Cheminformatics Commercial License Agreement provided with
** the Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and MS-Cheminformatics.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.TXT included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
**************************************************************************/

#pragma once

#include <Eigen/Dense>
#include <utility>

namespace adprocessor {

    template< typename T, size_t Ndim, size_t Ncomp >
    class PeakDecomposition {
        Eigen::Matrix< T, Ndim, Ncomp > A_;

        template< class Tuple, std::size_t... Is>
        void decomposition_impl( Eigen::Vector< T, Ndim >& b, const Tuple& t, std::index_sequence<Is...>) {
            ((b(Is) = std::get<Is>(t)), ...);
        }
    public:
        PeakDecomposition() : A_( Eigen::Matrix< T, Ndim, Ncomp >::Zero() ) {}
        PeakDecomposition( const Eigen::Matrix< T, Ndim, Ncomp >& a ) : A_( a ) {}

        template<typename... Args>
        std::pair< Eigen::Vector< T, Ndim >, Eigen::Vector< T, Ncomp > > operator()( Args... args ) {
            Eigen::Vector< T, Ndim > b;
            decomposition_impl( b, std::make_tuple( args... ), std::index_sequence_for< Args...>{} );
            return std::make_pair( b, A_.colPivHouseholderQr().solve(b) );
        }
    };

}
