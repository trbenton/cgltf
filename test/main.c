

#define CGLTF_IMPLEMENTATION
#include "../cgltf.h"

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int main(int argc, char** argv)
{
	cgltf_options options;
	cgltf_data* data;
	cgltf_result result;

	if (argc < 2)
	{
		printf("err\n");
		return -1;
	}


	memset(&options, 0, sizeof(cgltf_options));
	data = NULL;
	result = cgltf_parse_file(&options, argv[1], &data);

	if (result == cgltf_result_success)
		result = cgltf_load_buffers(&options, data, argv[1]);

	if (result == cgltf_result_success)
		result = cgltf_validate(data);

	printf("Result: %d\n", result);

	if (result == cgltf_result_success)
	{
		printf("Type: %u\n", data->file_type);
		printf("Meshes: %u\n", (unsigned)data->meshes_count);
	}

	cgltf_free(data);

	return result;
}
