#define hmsShadow(a,b,c) GEO_SHADOW(c,b,a),
#define hmsBegin() GEO_OPEN_NODE(),
#define hmsTrans(x,y,z) GEO_TRANSLATE(0x00, x,y,z),
#define hmsScale(s) GEO_SCALE(0x00, (u32)(s * 65536)),
#define hmsJoint(l,dl,x,y,z) GEO_ANIMATED_PART(l, x, y, z, dl),
#define hmsEnd() GEO_CLOSE_NODE(),
#define hmsExit() GEO_END(),
#define hmsBboard(x,y,z) GEO_BILLBOARD(),
#define hmsGfx(l,dl) GEO_DISPLAY_LIST(l, dl),
#define hmsGroup() GEO_NODE_START(),
#define hmsCProg(arg,func) GEO_ASM(arg, func),
#define hmsHeader(radius) GEO_CULLING_RADIUS(radius),
#define hmsSelect(count, function) GEO_SWITCH_CASE(count, function),
#define   RM_SURF                         1
#define   RM_SPRITE                       4
