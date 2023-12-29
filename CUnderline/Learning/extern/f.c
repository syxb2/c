/**
 * @brief
 *
 * @return int
 */
int f() {
  static int i = 0;
  return ++i;
}