int main() {
    long int num;
    int n;
    printf("TABLE OF POWERS OF TWO");
    printf("\nn    2 to the n");
    printf("\n--   -------");
    num = 1;

    for (n = 0; n < 11; ++n) {
      if (n == 0)
        num = 1;
      else
        num = num * 2;
      printf("\n%d    %d", n, num );
    }
    return 0;
  }