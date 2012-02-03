/*
 * Copyright (c) 2003, 2006 Matteo Frigo
 * Copyright (c) 2003, 2006 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Oct  4 10:27:48 EDT 2008 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 2 -name t2bv_2 -include t2b.h -sign 1 */

/*
 * This function contains 3 FP additions, 2 FP multiplications,
 * (or, 3 additions, 2 multiplications, 0 fused multiply/add),
 * 5 stack variables, and 4 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_twiddle_c.ml,v 1.14 2006-02-12 23:34:12 athena Exp $
 */

#include "t2b.h"

static const R *t2bv_2(R *ri, R *ii, const R *W, stride ios, INT m, INT dist)
{
     INT i;
     R *x;
     x = ii;
     for (i = m; i > 0; i = i - VL, x = x + (VL * dist), W = W + (TWVL * 2), MAKE_VOLATILE_STRIDE(ios)) {
	  V T1, T2, T3;
	  T1 = LD(&(x[0]), dist, &(x[0]));
	  T2 = LD(&(x[WS(ios, 1)]), dist, &(x[WS(ios, 1)]));
	  T3 = BYTW(&(W[0]), T2);
	  ST(&(x[0]), VADD(T1, T3), dist, &(x[0]));
	  ST(&(x[WS(ios, 1)]), VSUB(T1, T3), dist, &(x[WS(ios, 1)]));
     }
     return W;
}

static const tw_instr twinstr[] = {
     VTW(1),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 2, "t2bv_2", twinstr, &GENUS, {3, 2, 0, 0}, 0, 0, 0 };

void X(codelet_t2bv_2) (planner *p) {
     X(kdft_dit_register) (p, t2bv_2, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c -simd -compact -variables 4 -pipeline-latency 8 -n 2 -name t2bv_2 -include t2b.h -sign 1 */

/*
 * This function contains 3 FP additions, 2 FP multiplications,
 * (or, 3 additions, 2 multiplications, 0 fused multiply/add),
 * 5 stack variables, and 4 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_twiddle_c.ml,v 1.14 2006-02-12 23:34:12 athena Exp $
 */

#include "t2b.h"

static const R *t2bv_2(R *ri, R *ii, const R *W, stride ios, INT m, INT dist)
{
     INT i;
     R *x;
     x = ii;
     for (i = m; i > 0; i = i - VL, x = x + (VL * dist), W = W + (TWVL * 2), MAKE_VOLATILE_STRIDE(ios)) {
	  V T1, T3, T2;
	  T1 = LD(&(x[0]), dist, &(x[0]));
	  T2 = LD(&(x[WS(ios, 1)]), dist, &(x[WS(ios, 1)]));
	  T3 = BYTW(&(W[0]), T2);
	  ST(&(x[WS(ios, 1)]), VSUB(T1, T3), dist, &(x[WS(ios, 1)]));
	  ST(&(x[0]), VADD(T1, T3), dist, &(x[0]));
     }
     return W;
}

static const tw_instr twinstr[] = {
     VTW(1),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 2, "t2bv_2", twinstr, &GENUS, {3, 2, 0, 0}, 0, 0, 0 };

void X(codelet_t2bv_2) (planner *p) {
     X(kdft_dit_register) (p, t2bv_2, &desc);
}
#endif				/* HAVE_FMA */
