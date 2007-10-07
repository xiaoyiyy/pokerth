/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <playerdata.h>

using namespace std;

PlayerData::PlayerData(unsigned uniqueId, int number, PlayerType type, PlayerRights rights)
: m_uniqueId(uniqueId), m_number(number), m_type(type), m_rights(rights)
{
}

PlayerData::PlayerData(const PlayerData &other)
: m_uniqueId(other.GetUniqueId()), m_number(other.GetNumber()), m_name(other.GetName()),
  m_avatarFile(other.GetAvatarFile()), m_type(other.GetType()), m_rights(other.GetRights()),
  m_netSessionData(other.GetNetSessionData())
{
}

PlayerData::~PlayerData()
{
}

string
PlayerData::GetName() const
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	return m_name;
}

void
PlayerData::SetName(const std::string &name)
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	m_name = name;
}

string
PlayerData::GetAvatarFile() const
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	return m_avatarFile;
}

void
PlayerData::SetAvatarFile(const std::string &avatarFile)
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	m_avatarFile = avatarFile;
}

MD5Buf
PlayerData::GetAvatarMD5() const
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	return m_avatarMD5;
}
void
PlayerData::SetAvatarMD5(const MD5Buf &avatarMD5)
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	m_avatarMD5 = avatarMD5;
}

boost::shared_ptr<SessionData>
PlayerData::GetNetSessionData() const
{
	// setting/getting boost::shared_ptr is thread safe.
	return m_netSessionData;
}

void
PlayerData::SetNetSessionData(boost::shared_ptr<SessionData> session)
{
	// setting/getting boost::shared_ptr is thread safe.
	m_netSessionData = session;
}

boost::shared_ptr<AvatarData>
PlayerData::GetNetAvatarData() const
{
	return m_netAvatarData;
}

void
PlayerData::SetNetAvatarData(boost::shared_ptr<AvatarData> avatarData)
{
	m_netAvatarData = avatarData;
}

PlayerType
PlayerData::GetType() const
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	return m_type;
}

void
PlayerData::SetType(PlayerType type)
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	m_type = type;
}

PlayerRights
PlayerData::GetRights() const
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	return m_rights;
}

void
PlayerData::SetRights(PlayerRights rights)
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	m_rights = rights;
}

unsigned
PlayerData::GetUniqueId() const
{
	// const value - no mutex needed.
	return m_uniqueId;
}

int
PlayerData::GetNumber() const
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	return m_number;
}

void
PlayerData::SetNumber(int number)
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	m_number = number;
}

bool
PlayerData::operator<(const PlayerData &other) const
{
	boost::mutex::scoped_lock lock(m_dataMutex);
	return m_number < other.GetNumber();
}

