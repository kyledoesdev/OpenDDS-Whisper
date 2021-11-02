#include <stdio.h>
#include <json-c/json.h>

int main(int argc, char **argv) {

	FILE *fp;
	char buffer[1024];

	struct json_object *parsed_json;
	struct json_object *name;
	
	fp = fopen("test.json", "r");
	fread(buffer, 1024, 1, fp);
	fclose(fp);
	parsed_json = json_tokener_parse(buffer);
	json_object_object_get_ex(parsed_json, "name", &name);
	
	printf("Name: %s\n", json_object_get_string(name));
}
