/***********************************************************************
 Moses - statistical machine translation system
 Copyright (C) 2006-2012 University of Edinburgh
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
***********************************************************************/

#pragma once
#ifndef PCFG_EXTRACT_RULE_COLLECTION_H_
#define PCFG_EXTRACT_RULE_COLLECTION_H_

#include "pcfg-common/pcfg.h"

#include <boost/unordered_map.hpp>

#include <vector>

namespace Moses {
namespace PCFG {

// Contains PCFG rules and their counts.
class RuleCollection {
 public:
  typedef boost::unordered_map<std::vector<size_t>, size_t> RhsCountMap;
  typedef boost::unordered_map<size_t, RhsCountMap> Map;
  typedef Map::iterator iterator;
  typedef Map::const_iterator const_iterator;

  RuleCollection() {}

  iterator begin() { return collection_.begin(); }
  const_iterator begin() const { return collection_.begin(); }

  iterator end() { return collection_.end(); }
  const_iterator end() const { return collection_.end(); }

  void Add(size_t, const std::vector<size_t> &);
  void CreatePcfg(Pcfg &);

 private:
  Map collection_;
};

}  // namespace PCFG
}  // namespace Moses

#endif
