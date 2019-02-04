/* AWS Cloud Library
 * Read data from AWS Cloud
 * Write data to AWS Cloud
 *
 *				Author: Viki (a) Vignesh Natarajan 
 *				Contact: viki@vikilabs.org
 */

#ifndef AMAZON_AWS_H
#define AMAZON_AWS_H

typedef enum{
	HTTP_GET=1,
	HTTP_POST
}http_tx_type_e;

extern int AWS_ServerWrite(char *url, char *header, char *body);
extern int AWS_ServerRead(char *channel_key, char *channel_id, char *field);
#endif
