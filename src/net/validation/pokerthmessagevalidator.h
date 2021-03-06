/*****************************************************************************
 * PokerTH - The open source texas holdem engine                             *
 * Copyright (C) 2006-2012 Felix Hammer, Florian Thauer, Lothar May          *
 *                                                                           *
 * This program is free software: you can redistribute it and/or modify      *
 * it under the terms of the GNU Affero General Public License as            *
 * published by the Free Software Foundation, either version 3 of the        *
 * License, or (at your option) any later version.                           *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU Affero General Public License for more details.                       *
 *                                                                           *
 * You should have received a copy of the GNU Affero General Public License  *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *                                                                           *
 *                                                                           *
 * Additional permission under GNU AGPL version 3 section 7                  *
 *                                                                           *
 * If you modify this program, or any covered work, by linking or            *
 * combining it with the OpenSSL project's OpenSSL library (or a             *
 * modified version of that library), containing parts covered by the        *
 * terms of the OpenSSL or SSLeay licenses, the authors of PokerTH           *
 * (Felix Hammer, Florian Thauer, Lothar May) grant you additional           *
 * permission to convey the resulting work.                                  *
 * Corresponding Source for a non-source form of such a combination          *
 * shall include the source code for the parts of OpenSSL used as well       *
 * as that of the covered work.                                              *
 *****************************************************************************/
/* PokerTH network packet validation. */

#ifndef _POKERTHMESSAGEVALIDATOR_H_
#define _POKERTHMESSAGEVALIDATOR_H_

#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

class PokerTHMessage;
class AuthMessageValidator;
class LobbyMessageValidator;
class GameMessageValidator;

#define VALIDATE_IS_UINT16(__val) ((__val) <= 65535)
#define VALIDATE_STRING_SIZE(__str, __minsize, __maxsize) ((__str).size() >= (__minsize) && (__str).size() <= (__maxsize))
#define VALIDATE_UINT_RANGE(__val, __minval, __maxval) ((__val) >= (__minval) && (__val) <= (__maxval))
#define VALIDATE_UINT_UPPER(__val, __maxval) ((__val) <= (__maxval))
#define VALIDATE_LIST_SIZE(__l, __minsize, __maxsize) ((__l).size() >= (__minsize) && (__l).size() <= (__maxsize))

class PokerTHMessageValidator
{
public:
	PokerTHMessageValidator();

	bool IsValidMessage(const PokerTHMessage &msg) const;

protected:
	static bool ValidateAnnounceMessage(const PokerTHMessage &msg);
	bool ValidateAuthMessage(const PokerTHMessage &msg);
	bool ValidateLobbyMessage(const PokerTHMessage &msg);
	bool ValidateGameMessage(const PokerTHMessage &msg);

	typedef boost::function<bool (const PokerTHMessage &)> ValidateFunctor;
	typedef std::map<int, ValidateFunctor> ValidateFunctorMap;
private:

	ValidateFunctorMap m_validationMap;
	boost::shared_ptr<AuthMessageValidator> m_authValidator;
	boost::shared_ptr<LobbyMessageValidator> m_lobbyValidator;
	boost::shared_ptr<GameMessageValidator> m_gameValidator;
};

#endif

