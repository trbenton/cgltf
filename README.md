# :diamond_shape_with_a_dot_inside: cgltf

**C89 Fork of Single-file/stb-style C glTF loader for older compilers**

Direct port of cgltf to C89. The writer portion has not been ported. gltf.h was compiled and tested successfully in C89 mode with gcc and VS 6.0. I had to make a few changes due to the lack of 64 bit types, but it doesn't seem to have caused any major problems as all the test files still load.
