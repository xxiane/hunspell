/* Copyright 2016-2017 Dimitrij Mijoski
 *
 * This file is part of Hunspell-2.
 *
 * Hunspell-2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Hunspell-2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Hunspell-2.	If not, see <http://www.gnu.org/licenses/>.
 *
 * Hunspell 2 is based on Hunspell v1 and MySpell.
 * Hunspell v1 is Copyright (C) 2002-2017 Németh László
 * MySpell is Copyright (C) 2002 Kevin Hendricks.
 */

/**
 * @file string_utils.hxx
 * @brief String algorithms not dependent on locale.
 */

#ifndef HUNSPELL_STRING_UTILS_HXX
#define HUNSPELL_STRING_UTILS_HXX

#include <string>
#include <vector>

namespace Hunspell {

template <class CharT, class CharOrStr, class OutIt>
OutIt split(const std::basic_string<CharT>& s, CharOrStr sep, OutIt out)
{
	using size_type = typename std::basic_string<CharT>::size_type;
	size_type sz = s.size();
	size_type i1 = 0;
	size_type i2;
	do {
		i2 = s.find(sep, i1);
		*out++ = s.substr(i1, i2 - i1);
		i1 = i2 + 1;
		// i2 gets s.npos after the last separator
		// lenth of i2-i1 will always go past the end
		// yet that is defined
	} while (i2 != s.npos);
	return out;
}

template <class CharT, class CharOrStr, class OutIt>
OutIt split_on_any_of(const std::basic_string<CharT>& s, CharOrStr sep,
                      OutIt out)
{
	using size_type = typename std::basic_string<CharT>::size_type;
	size_type sz = s.size();
	size_type i1 = 0;
	size_type i2;
	do {
		i2 = s.find_first_of(sep, i1);
		*out++ = s.substr(i1, i2 - i1);
		i1 = i2 + 1;
		// i2 gets s.npos after the last separator
		// lenth of i2-i1 will always go past the end
		// yet that is defined
	} while (i2 != s.npos);
	return out;
}

template <class To>
struct cast_lambda {
	template <class From>
	To operator()(From& f) const
	{
		return static_cast<To>(f);
	}
};
}
#endif
