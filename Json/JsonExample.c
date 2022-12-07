#include<stdio.h>
#include<json-c/json.h>

#define EXAMPLE_JSON	"./example.json"
#define NULL_NULL		"NULL"
#define BOOL_BOOLEAN	"BOOLEAN"
#define STR_STRING		"STRING"
#define NUM_INTEGER		"NUMBER"
#define NUM_DOUBLE		"DOUBLE"
#define ARR_ARRAY		"ARRAY"
#define OBJ_OBJECT		"OBJECT"
#define NULL_MEMBER_NULL	"MEMBER_NULL"
#define BOOL_MEMBER_BOOLEAN	"MEMBER_BOOLEAN"
#define STR_MEMBER_STRING	"MEMBER_STRING"
#define NUM_MEMBER_INTEGER	"MEMBER_NUMBER"
#define NUM_MEMBER_DOUBLE	"MEMBER_DOUBLE"
#define ARR_MEMBER_ARRAY	"MEMBER_ARRAY"

int write_to_json_file(char* filename)
{
	int ret = 0;
	json_object *json_obj = NULL;
	json_object *array_obj = NULL;
	json_object *new_obj = NULL;
	json_object *tmp_obj = NULL;
	json_object *tmp1_obj = NULL;

	//new a base object
	json_obj = json_object_new_object();
	if (!json_obj)
	{
		printf("Cannot create object\n");
		ret = -1;
		goto error;
	}

	//new a null
	json_object_object_add(json_obj, NULL_NULL, NULL);

	//new a boolean
	tmp_obj = json_object_new_boolean(1);
	if (!tmp_obj)
	{
		printf("Cannot create boolean object for %s\n", BOOL_BOOLEAN);
		ret = -1;
		goto error;
	}
	json_object_object_add(json_obj, BOOL_BOOLEAN, tmp_obj);
	tmp_obj = NULL;

	//new a string
	tmp_obj = json_object_new_string("string");
	if (!tmp_obj)
	{
		printf("Cannot create string object for %s\n", STR_STRING);
		ret = -1;
		goto error;
	}
	json_object_object_add(json_obj, STR_STRING, tmp_obj);
	tmp_obj = NULL;

	//new a integer
	tmp_obj = json_object_new_int(100);
	if (!tmp_obj)
	{
		printf("Cannot create number object for %s\n", NUM_INTEGER);
		ret = -1;
		goto error;
	}
	json_object_object_add(json_obj, NUM_INTEGER, tmp_obj);
	tmp_obj = NULL;

	//new a double
	tmp_obj = json_object_new_double(3.1415926);
	if (!tmp_obj)
	{
		printf("Cannot create double object for %s\n", NUM_DOUBLE);
		ret = -1;
		goto error;
	}
	json_object_object_add(json_obj, NUM_DOUBLE, tmp_obj);
	tmp_obj = NULL;

	//new a array
	array_obj = json_object_new_array();
	if (!array_obj)
	{
		printf("Cannot create array object\n");
		ret = -1;
		goto error;
	}

	//new a string and add to the array
	new_obj = json_object_new_string("str1");
	if (!new_obj)
	{
		printf("Cannot create string object for %s\n", ARR_ARRAY);
		ret = -1;
		goto error;
	}
	json_object_array_add(array_obj, new_obj);
	new_obj = NULL;

	//new a string and add to the array
	new_obj = json_object_new_string("str2");
	if (!new_obj)
	{
		printf("Cannot create string object for %s\n", ARR_ARRAY);
		ret = -1;
		goto error;
	}
	json_object_array_add(array_obj, new_obj);
	new_obj = NULL;

	//new a string and add to the array
	new_obj = json_object_new_string("str3");
	if (!new_obj)
	{
		printf("Cannot create string object for %s\n", ARR_ARRAY);
		ret = -1;
		goto error;
	}
	json_object_array_add(array_obj, new_obj);
	new_obj = NULL;

	//add array to the base object
	json_object_object_add(json_obj, ARR_ARRAY, array_obj);
	array_obj = NULL;

	//new an object
	tmp_obj = json_object_new_object();
	if (!tmp_obj)
	{
		printf("Cannot create object\n");
		ret = -1;
		goto error;
	}

	//add a null to the object
	json_object_object_add(tmp_obj, NULL_MEMBER_NULL, NULL);

	//new a boolean and add to the object
	tmp1_obj = json_object_new_boolean(0);
	if (!tmp1_obj)
	{
		printf("Cannot create boolean object for %s\n", BOOL_MEMBER_BOOLEAN);
		ret = -1;
		goto error;
	}
	json_object_object_add(tmp_obj, BOOL_MEMBER_BOOLEAN, tmp1_obj);
	tmp1_obj = NULL;

	//new a string and add to the object
	tmp1_obj = json_object_new_string("string");
	if (!tmp1_obj)
	{
		printf("Cannot create string object for %s\n", STR_MEMBER_STRING);
		ret = -1;
		goto error;
	}
	json_object_object_add(tmp_obj, STR_MEMBER_STRING, tmp1_obj);
	tmp1_obj = NULL;

	//new a integer and add to the object
	tmp1_obj = json_object_new_int(200);
	if (!tmp1_obj)
	{
		printf("Cannot create number object for %s\n", NUM_MEMBER_INTEGER);
		ret = -1;
		goto error;
	}
	json_object_object_add(tmp_obj, NUM_MEMBER_INTEGER, tmp1_obj);
	tmp1_obj = NULL;

	//new a double and add to the object
	tmp1_obj = json_object_new_double(0.123456789);
	if (!tmp1_obj)
	{
		printf("Cannot create double object for %s\n", NUM_MEMBER_DOUBLE);
		ret = -1;
		goto error;
	}
	json_object_object_add(tmp_obj, NUM_MEMBER_DOUBLE, tmp1_obj);
	tmp1_obj = NULL;

	//new a array
	array_obj = json_object_new_array();
	if (!array_obj)
	{
		printf("Cannot create array object\n");
		ret = -1;
		goto error;
	}

	//new a integer and add to array
	new_obj = json_object_new_int(1);
	if (!new_obj)
	{
		printf("Cannot create string object for %s\n", ARR_MEMBER_ARRAY);
		ret = -1;
		goto error;
	}
	json_object_array_add(array_obj, new_obj);
	new_obj = NULL;

	//new a integer and add to array
	new_obj = json_object_new_int(2);
	if (!new_obj)
	{
		printf("Cannot create string object for %s\n", ARR_MEMBER_ARRAY);
		ret = -1;
		goto error;
	}
	json_object_array_add(array_obj, new_obj);
	new_obj = NULL;

	//new a integer and add to array
	new_obj = json_object_new_int(3);
	if (!new_obj)
	{
		printf("Cannot create string object for %s\n", ARR_MEMBER_ARRAY);
		ret = -1;
		goto error;
	}
	json_object_array_add(array_obj, new_obj);
	new_obj = NULL;

	//add array to the object
	json_object_object_add(tmp_obj, ARR_MEMBER_ARRAY, array_obj);
	array_obj = NULL;

	//add the object to base object
	json_object_object_add(json_obj, OBJ_OBJECT, tmp_obj);
	tmp_obj = NULL;

	//write the base object to write.json
	json_object_to_file(filename, json_obj);

error:
	json_object_put(tmp1_obj);
	json_object_put(tmp_obj);
	json_object_put(new_obj);
	json_object_put(array_obj);
	json_object_put(json_obj);

	return ret;
}

int read_from_json_file(char *filename)
{
	int ret = 0;
	json_object *test_obj = NULL;
	json_object *tmp_obj = NULL;
	json_object *tmp1_obj = NULL;
	json_object *tmp2_obj = NULL;

	//get json object from file
	test_obj = json_object_from_file(filename);
	if (!test_obj)
	{
		printf("Cannot open %s\n", filename);
		ret = -1;
		goto error;
	}

	//get null
	tmp_obj = json_object_object_get(test_obj, NULL_NULL);
	if (tmp_obj)
	{
		printf("Cannot get %s object\n", NULL_NULL);
		ret = -1;
		goto error;
	}
	printf("%s = %s\n", NULL_NULL, "null");

	//get boolean
	tmp_obj = json_object_object_get(test_obj, BOOL_BOOLEAN);
	if (!tmp_obj)
	{
		printf("Cannot get %s object\n", BOOL_BOOLEAN);
		ret = -1;
		goto error;
	}
	printf("%s = %s\n", BOOL_BOOLEAN, ((json_object_get_boolean(tmp_obj))?("TRUE"):("FALSE")));

	//get string
	tmp_obj = json_object_object_get(test_obj, STR_STRING);
	if (!tmp_obj)
	{
		printf("Cannot get %s object\n", STR_STRING);
		ret = -1;
		goto error;
	}
	printf("%s = %s\n", STR_STRING, json_object_get_string(tmp_obj));

	//get integer
	tmp_obj = json_object_object_get(test_obj, NUM_INTEGER);
	if (!tmp_obj)
	{
		printf("Cannot get %s object\n", NUM_INTEGER);
		ret = -1;
		goto error;
	}
	printf("%s = %d\n", NUM_INTEGER, json_object_get_int(tmp_obj));

	//get double
	tmp_obj = json_object_object_get(test_obj, NUM_DOUBLE);
	if (!tmp_obj)
	{
		printf("Cannot get %s object\n", NUM_DOUBLE);
		ret = -1;
		goto error;
	}
	printf("%s = %F\n", NUM_DOUBLE, json_object_get_double(tmp_obj));

	//get array
	tmp_obj = json_object_object_get(test_obj, ARR_ARRAY);
	if (!tmp_obj)
	{
		printf("Cannot get %s object\n", ARR_ARRAY);
		ret = -1;
		goto error;
	}
	//get the length of the array
	printf("%s size = %d\n", ARR_ARRAY, json_object_array_length(tmp_obj));

	//get the value of array[0]
	tmp1_obj = json_object_array_get_idx(tmp_obj, 0);
	printf("%s[0] = %s\n", ARR_ARRAY, json_object_get_string(tmp1_obj));

	//get the value of array[1]
	tmp1_obj = json_object_array_get_idx(tmp_obj, 1);
	printf("%s[1] = %s\n", ARR_ARRAY, json_object_get_string(tmp1_obj));

	//get the value of array[2]
	tmp1_obj = json_object_array_get_idx(tmp_obj, 2);
	printf("%s[2] = %s\n", ARR_ARRAY, json_object_get_string(tmp1_obj));

	//get object
	tmp_obj = json_object_object_get(test_obj, OBJ_OBJECT);
	if (!tmp_obj)
	{
		printf("Cannot get %s object\n", OBJ_OBJECT);
		ret = -1;
		goto error;
	}

	//get null within a object
	tmp1_obj = json_object_object_get(tmp_obj, NULL_MEMBER_NULL);
	if (tmp1_obj)
	{
		printf("Cannot get %s object\n", NULL_MEMBER_NULL);
		ret = -1;
		goto error;
	}
	printf("%s = %s\n", NULL_MEMBER_NULL, "null");

	//get boolean within a object
	tmp1_obj = json_object_object_get(tmp_obj, BOOL_MEMBER_BOOLEAN);
	if (!tmp1_obj)
	{
		printf("Cannot get %s object\n", BOOL_MEMBER_BOOLEAN);
		ret = -1;
		goto error;
	}
	printf("%s = %s\n", BOOL_MEMBER_BOOLEAN, ((json_object_get_boolean(tmp1_obj))?("TRUE"):("FALSE")));

	//get string within a object
	tmp1_obj = json_object_object_get(tmp_obj, STR_MEMBER_STRING);
	if (!tmp1_obj)
	{
		printf("Cannot get %s object\n", STR_MEMBER_STRING);
		ret = -1;
		goto error;
	}
	printf("%s = %s\n", STR_MEMBER_STRING, json_object_get_string(tmp1_obj));

	//get integer within a object
	tmp1_obj = json_object_object_get(tmp_obj, NUM_MEMBER_INTEGER);
	if (!tmp1_obj)
	{
		printf("Cannot get %s object\n", NUM_MEMBER_INTEGER);
		ret = -1;
		goto error;
	}
	printf("%s = %d\n", NUM_MEMBER_INTEGER, json_object_get_int(tmp1_obj));

	//get double within a object
	tmp1_obj = json_object_object_get(tmp_obj, NUM_MEMBER_DOUBLE);
	if (!tmp1_obj)
	{
		printf("Cannot get %s object\n", NUM_MEMBER_DOUBLE);
		ret = -1;
		goto error;
	}
	printf("%s = %F\n", NUM_MEMBER_DOUBLE, json_object_get_double(tmp1_obj));

	//get array within a object
	tmp1_obj = json_object_object_get(tmp_obj, ARR_MEMBER_ARRAY);
	if (!tmp1_obj)
	{
		printf("Cannot get %s object\n", ARR_MEMBER_ARRAY);
		ret = -1;
		goto error;
	}
	//get the length of the array within a object
	printf("%s size = %d\n", ARR_MEMBER_ARRAY, json_object_array_length(tmp1_obj));

	//get the value of array[0] within a object
	tmp2_obj = json_object_array_get_idx(tmp1_obj, 0);
	printf("%s[0] = %d\n", ARR_MEMBER_ARRAY, json_object_get_int(tmp2_obj));

	//get the value of array[0] within a object
	tmp2_obj = json_object_array_get_idx(tmp1_obj, 1);
	printf("%s[1] = %d\n", ARR_MEMBER_ARRAY, json_object_get_int(tmp2_obj));

	//get the value of array[0] within a object
	tmp2_obj = json_object_array_get_idx(tmp1_obj, 2);
	printf("%s[2] = %d\n", ARR_MEMBER_ARRAY, json_object_get_int(tmp2_obj));

error:
	json_object_put(test_obj);

	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	ret = write_to_json_file(EXAMPLE_JSON);
	if (ret != 0)
		printf("Fail to write a json file\n");

	ret = read_from_json_file(EXAMPLE_JSON);
	if (ret != 0)
		printf("Fail to read a json file\n");

	return 0;
}