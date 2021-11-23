#ifndef CSMANIP_H
#define CSMANIP_H

#include <string>
#include <map>
#include <utility>

namespace osm
 {
  //Type aliases declarations:
  using string_map = std::map <std::string, std::string>;
  using string_pair_map = std::map <std::string, std::pair<std::string, std::string>>;

  //Variables declaration:
  extern string_map col,
                    sty,
                    rst;
  extern string_pair_map crs;

  //Functions declaration:
  extern std::string feat ( string_map & generic_map, std::string feat_string );
  extern std::string feat ( string_pair_map & generic_map, std::string feat_string, int feat_int );
  extern std::string reset ( std::string reset_string );
 }
      
#endif