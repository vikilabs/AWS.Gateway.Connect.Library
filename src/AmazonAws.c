/* AWS Cloud Library
 * Read data from AWS Cloud
 * Write data to AWS Cloud
 *
 *				Author: Viki (a) Vignesh Natarajan 
 *				Contact: viki@vikilabs.org
 */

#include <stdio.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <string.h>
#include "AmazonAws.h"

int https_post(char *url, char *header, char *body)
{
	CURL *curl;
	CURLcode res;
	struct curl_slist *custom_header = NULL;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if(curl) {
		custom_header = curl_slist_append(custom_header, "Content-Type: application/json");
		custom_header = curl_slist_append(custom_header, header);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, custom_header);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
		
		printf("\n#################################################################\n");
		res = curl_easy_perform(curl);
		printf("\n#################################################################\n");

		if(res != CURLE_OK){
			fprintf(stderr, "[ failure ] curl_easy_perform() %s\n", curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
		curl_slist_free_all(custom_header);
	}

	curl_global_cleanup();
	return 0;
}

#if 0
int https_get(char *url)
{
	http_transmit(true, HTTP_GET, url, NULL);
	return 0;
}
#endif 

/* channel_key : AWS Write Api Key
 * field : <1 to xx> (To write value to specific field)
 * value : value to assign for the field
 */
int AWS_ServerWrite(char *url, char *header, char *body)
{
	https_post(url, header, body);
	printf("\n");
	return 0;
}

#if 0 
/* channel_key : AWS Read Api Key
 * channel_id  : AWS Channel ID
 * field_index : 0 (To read all fields) [currently not supported] 
 *				 <1 to xx> (To read specific field)
 */
int AWS_ServerRead(char *channel_key, char *channel_id, char *field)
{
ar request_url[2048];
	strcpy(request_url, AWS_HTTP_URL);
	strcat(request_url, "/");
	strcat(request_url, "channels/");
	strcat(request_url, channel_id);
	strcat(request_url, "/fields/");
	strcat(request_url, field);
	strcat(request_url, ".json?api_key=");
	strcat(request_url, channel_key);
	strcat(request_url, "&results=2");
	printf("[ URL ] [ %s ]\n", request_url);
	http_get(request_url);
	printf("\n");
	return 0;
}
#endif 


