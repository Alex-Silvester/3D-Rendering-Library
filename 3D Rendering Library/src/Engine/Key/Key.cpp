#include "Key.h"

template<KeyID ID>
inline bool Key<ID>::pressed()
{
  bool initial_flag = m_held;
  m_held = glfwGetKey(m_window->glfwWindow(), ID) == GLFW_PRESS;

  //if the key is pressed and the check was the first press
  return m_held && (m_held != initial_flag);
}

template<KeyID ID>
inline bool Key<ID>::held()
{
  if (m_held) return true;

  m_held = glfwGetKey(m_window->glfwWindow(), ID) == GLFW_PRESS;
  return m_held;
}

template<KeyID ID>
inline bool Key<ID>::released()
{
  m_held = glfwGetKey(m_window->glfwWindow(), ID) == GLFW_PRESS;

  return m_held;
}