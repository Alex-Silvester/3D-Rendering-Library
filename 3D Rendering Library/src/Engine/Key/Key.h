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
  Key operator()(const Key &) = delete;

  static void addWindow(const std::shared_ptr<Window> &window)
  {

    m_window = window;
  }

  static bool pressed()
  {
    if (m_window.get() == nullptr)
    {
      std::cerr << "Key {" << ID << "} requires the window\n";
      return false;
    }

    bool initial_flag = m_held;
    m_held = glfwGetKey(m_window->glfwWindow(), ID) == GLFW_PRESS;

    //if the key is pressed and the check was the first press
    return m_held && (m_held != initial_flag);
  }

  static bool held()
  {
    if (m_window.get() == nullptr)
    {
      std::cerr << "Key {" << ID << "} requires the window\n";
      return false;
    }

    if (m_held) return true;

    m_held = glfwGetKey(m_window->glfwWindow(), ID) == GLFW_PRESS;
    return m_held;
  }

  static bool released()
  {
    if (m_window.get() == nullptr)
    {
      std::cerr << "Key {" << ID << "} requires the window\n";
      return false;
    }

    m_held = glfwGetKey(m_window->glfwWindow(), ID) == GLFW_PRESS;

    return m_held;
  }

private:

  static std::shared_ptr<Window> m_window;
  
  inline static bool m_held = false;;

};

template<KeyID ID>
std::shared_ptr<Window> Key<ID>::m_window;
