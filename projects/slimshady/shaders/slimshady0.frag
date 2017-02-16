#version 120

// Custom parameters from Sprite
uniform vec3 customParams[8];

// Interpolated values from the vertex shaders
varying vec2 UV;

// Values that stay constant for the whole mesh.
uniform sampler2D textureSampler;
uniform vec4 blendColor;

void main()
{
	// gl_FragCoord = screen coords. bottom-left: 0.5,0.5 top-right: 1279.5,719.5
	vec2 mapped = vec2(gl_FragCoord.x / 1280.0, gl_FragCoord.y / 720.0); // between 0.0f and 1.0f
	gl_FragColor = vec4(sin(gl_FragCoord.x/10), cos(gl_FragCoord.y/10), mapped.y, 1.0);
}