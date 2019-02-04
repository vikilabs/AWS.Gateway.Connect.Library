#include "AmazonAws.h"
#define AWS_GATEWAY_URL ""
int main(void)
{
  char *header = "x-api-key:123456";
  char *body = "{Test:Test}";
  AWS_ServerWrite(AWS_GATEWAY_URL, header, body);
  return 0;
}
