/**
 * @file   stringize.h
 * @author Nat Goodspeed
 * @date   2008-12-17
 * @brief  stringize(item) template function and STRINGIZE(expression) macro
 * 
 * $LicenseInfo:firstyear=2008&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2010, Linden Research, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

#if ! defined(LL_STRINGIZE_H)
#define LL_STRINGIZE_H

#include <sstream>
#include <boost/phoenix/phoenix.hpp>
#include "llstring.h"

/**
 * gstringize(item) encapsulates an idiom we use constantly, using
 * operator<<(std::ostringstream&, TYPE) followed by std::ostringstream::str()
 * or their wstring equivalents
 * to render a string expressing some item.
 */
template <typename CHARTYPE, typename T>
std::basic_string<CHARTYPE> gstringize(const T& item)
{
    std::basic_ostringstream<CHARTYPE> out;
    out << item;
    return out.str();
}

/**
 *partial specialization of stringize for handling wstring
 *TODO: we should have similar specializations for wchar_t[] but not until it is needed.
 */
inline std::string stringize(const std::wstring& item)
{
    LL_WARNS() << "WARNING:  Possible narrowing" << LL_ENDL;
    
    std::string s;
    
    s = wstring_to_utf8str(item);
    return gstringize<char>(s);
}

/**
 * Specialization of gstringize for std::string return types
 */
template <typename T>
std::string stringize(const T& item)
{
    return gstringize<char>(item);
}

/**
 * Specialization for generating wstring from string.
 * Both a convenience function and saves a miniscule amount of overhead.
 */
inline std::wstring wstringize(const std::string& item)
{
    return gstringize<wchar_t>(item.c_str());
}

/**
 * Specialization of gstringize for std::wstring return types
 */
template <typename T>
std::wstring wstringize(const T& item)
{
    return gstringize<wchar_t>(item);
}

/**
 * stringize_f(functor)
 */
template <typename Functor>
std::string stringize_f(Functor const & f)
{
    std::ostringstream out;
    f(out);
    return out.str();
}

/**
 * STRINGIZE(item1 << item2 << item3 ...) effectively expands to the
 * following:
 * @code
 * std::ostringstream out;
 * out << item1 << item2 << item3 ... ;
 * return out.str();
 * @endcode
 */
#define STRINGIZE(EXPRESSION) (stringize_f(boost::phoenix::placeholders::arg1 << EXPRESSION))


/**
 * destringize(str)
 * defined for symmetry with stringize
 * *NOTE - this has distinct behavior from boost::lexical_cast<T> regarding
 * leading/trailing whitespace and handling of bad_lexical_cast exceptions
 */
template <typename T>
T destringize(std::string const & str)
{
	T val;
    std::istringstream in(str);
	in >> val;
    return val;
}

/**
 * destringize_f(str, functor)
 */
template <typename Functor>
void destringize_f(std::string const & str, Functor const & f)
{
    std::istringstream in(str);
    f(in);
}

/**
 * DESTRINGIZE(str, item1 >> item2 >> item3 ...) effectively expands to the
 * following:
 * @code
 * std::istringstream in(str);
 * in >> item1 >> item2 >> item3 ... ;
 * @endcode
 */
#define DESTRINGIZE(STR, EXPRESSION) (destringize_f((STR), (boost::phoenix::placeholders::arg1 >> EXPRESSION)))


#endif /* ! defined(LL_STRINGIZE_H) */
