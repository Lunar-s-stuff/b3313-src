#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "geo_commands_leek.h"
#include "make_const_nonconst.h"

extern Gfx RCP_newrabbit_base0[];
extern Gfx RCP_newrabbit_base1[];
extern Gfx RCP_newrabbit_base2[];
extern Gfx RCP_newrabbit_base3[];
extern Gfx RCP_newrabbit_base4[];
extern Gfx RCP_newrabbit_base5[];
extern Gfx RCP_newrabbit_base6[];
extern Gfx RCP_newrabbit_base7[];
extern Gfx RCP_newrabbit_base8[];
extern Gfx RCP_newrabbit_base9[];
extern Gfx RCP_newrabbit_base10[];
extern Gfx RCP_newrabbit_base11[];

// 0x0D000448
const GeoLayout mips_geo[] = {
	0, 0,
	
	hmsShadow(50, 200, 1)
	hmsBegin()
		hmsScale(0.25f)
		hmsBegin()
		    hmsJoint(RM_SURF,NULL, 0,0, 0)										/* chn10_1		*/
			hmsBegin()
				hmsJoint(RM_SURF,RCP_newrabbit_base11, 0, 5, 0)					/* r_body1		*/
				hmsBegin()
					hmsJoint(RM_SURF,RCP_newrabbit_base10, 68, 0, 0)				/* r_face1		*/
					hmsBegin()

						hmsJoint(RM_SURF,NULL, 70, -28, 32)							/* chn7			*/
						hmsBegin()
							hmsJoint(RM_SURF,RCP_newrabbit_base1, 0, 0, 0)			/* r_learB1		*/
							hmsBegin()
								hmsJoint(RM_SURF,RCP_newrabbit_base0,  77, 0, 0)	/* r_learA1		*/
							hmsEnd()
						hmsEnd()

					 	hmsJoint(RM_SURF,NULL, 70, -28, -32)						/* chn9			*/
						hmsBegin()
							hmsJoint(RM_SURF,RCP_newrabbit_base3, 0, 0, 0)			/* r_rearB1		*/
							hmsBegin()
								hmsJoint(RM_SURF,RCP_newrabbit_base2,  77, 0, 0)	/* r_rearA1		*/
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF,NULL, -28, -4, 40)								/* chn2			*/
					hmsBegin()
						hmsJoint(RM_SURF,RCP_newrabbit_base6, 0, 0, 0)				/* r_lleg1		*/
						hmsBegin()
							hmsJoint(RM_SURF,RCP_newrabbit_base5, 42, 0, 0)		/* r_lfootB1	*/
							hmsBegin()
								hmsJoint(RM_SURF,RCP_newrabbit_base4, 46, 0, 0)	/* r_lfootA1	*/
							hmsEnd()
						hmsEnd()
					hmsEnd()

					hmsJoint(RM_SURF,NULL, -28, -4, -40)							/* chn4	  		*/
					hmsBegin()
						hmsJoint(RM_SURF,RCP_newrabbit_base9, 0, 0, 0)				/* r_rleg1		*/
						hmsBegin()
							hmsJoint(RM_SURF,RCP_newrabbit_base8, 42, 0, 0)		/* r_rfootB1	*/
							hmsBegin()
								hmsJoint(RM_SURF,RCP_newrabbit_base7, 46, 0, 0)	/* r_rfootA1	*/
							hmsEnd()
						hmsEnd()
					hmsEnd()
				hmsEnd()
			hmsEnd()
		hmsEnd()
	hmsEnd()
 hmsEnd()
 hmsExit()
};
