#pragma once

#include "../../Dependencies.h"

class Window;

using KeyID = int;

template<KeyID ID>
class Key
{
public:

  //delete all the constructors
  Key() = delete;
  Key(const Key &) = delete;
  Key operator(const Key &) = delete;

  inline static bool pressed();
  inline static bool held();
  inline static bool released();

private:

  std::shared_ptr<Window> m_window = std::make_shared<Window>(nullptr);
  
  static bool m_held = false;

};
