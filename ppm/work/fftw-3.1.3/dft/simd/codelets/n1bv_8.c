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
/* Generated on Sat Oct  4 10:25:25 EDT 2008 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 8 -name n1bv_8 -include n1b.h */

/*
 * This function contains 26 FP additions, 10 FP multiplications,
 * (or, 16 additions, 0 multiplications, 10 fused multiply/add),
 * 30 stack variables, and 16 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_notw_c.ml,v 1.17 2006-02-12 23:34:12 athena Exp $
 */

#include "n1b.h"

static void n1bv_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     INT i;
     const R *xi;
     R *xo;
     xi = ii;
     xo = io;
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	  V T1, T2, Tc, Td, T4, T5, T7, T8;
	  T1 = LD(&(xi[0]), ivs, &(xi[0]));
	  T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	  Tc = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	  Td = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
	  T4 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	  T5 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	  T7 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	  T8 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	  {
	       V T3, Tj, Te, Tk, T6, Tm, T9, Tn, Tp, Tl;
	       T3 = VSUB(T1, T2);
	       Tj = VADD(T1, T2);
	       Te = VSUB(Tc, Td);
	       Tk = VADD(Tc, Td);
	       T6 = VSUB(T4, T5);
	       Tm = VADD(T4, T5);
	       T9 = VSUB(T7, T8);
	       Tn = VADD(T7, T8);
	       Tp = VADD(Tj, Tk);
	       Tl = VSUB(Tj, Tk);
	       {
		    V Tq, To, Ta, Tf;
		    Tq = VADD(Tm, Tn);
		    To = VSUB(Tm, Tn);
		    Ta = VADD(T6, T9);
		    Tf = VSUB(T6, T9);
		    {
			 V Tg, Ti, Tb, Th;
			 ST(&(xo[WS(os, 2)]), VFMAI(To, Tl), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 6)]), VFNMSI(To, Tl), ovs, &(xo[0]));
			 ST(&(xo[0]), VADD(Tp, Tq), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 4)]), VSUB(Tp, Tq), ovs, &(xo[0]));
			 Tg = VFNMS(LDK(KP707106781), Tf, Te);
			 Ti = VFMA(LDK(KP707106781), Tf, Te);
			 Tb = VFNMS(LDK(KP707106781), Ta, T3);
			 Th = VFMA(LDK(KP707106781), Ta, T3);
			 ST(&(xo[WS(os, 7)]), VFNMSI(Ti, Th), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 1)]), VFMAI(Ti, Th), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 5)]), VFMAI(Tg, Tb), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 3)]), VFNMSI(Tg, Tb), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
}

static const kdft_desc desc = { 8, "n1bv_8", {16, 0, 10, 0}, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1bv_8) (planner *p) {
     X(kdft_register) (p, n1bv_8, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 8 -name n1bv_8 -include n1b.h */

/*
 * This function contains 26 FP additions, 2 FP multiplications,
 * (or, 26 additions, 2 multiplications, 0 fused multiply/add),
 * 22 stack variables, and 16 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_notw_c.ml,v 1.17 2006-02-12 23:34:12 athena Exp $
 */

#include "n1b.h"

static void n1bv_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     INT i;
     const R *xi;
     R *xo;
     xi = ii;
     xo = io;
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	  V Ta, Tk, Te, Tj, T7, Tn, Tf, Tm;
	  {
	       V T8, T9, Tc, Td;
	       T8 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       T9 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
	       Ta = VSUB(T8, T9);
	       Tk = VADD(T8, T9);
	       Tc = LD(&(xi[0]), ivs, &(xi[0]));
	       Td = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	       Te = VSUB(Tc, Td);
	       Tj = VADD(Tc, Td);
	       {
		    V T1, T2, T3, T4, T5, T6;
		    T1 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    T2 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    T3 = VSUB(T1, T2);
		    T4 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    T5 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    T6 = VSUB(T4, T5);
		    T7 = VMUL(LDK(KP707106781), VSUB(T3, T6));
		    Tn = VADD(T4, T5);
		    Tf = VMUL(LDK(KP707106781), VADD(T3, T6));
		    Tm = VADD(T1, T2);
	       }
	  }
	  {
	       V Tb, Tg, Tp, Tq;
	       Tb = VBYI(VSUB(T7, Ta));
	       Tg = VSUB(Te, Tf);
	       ST(&(xo[WS(os, 3)]), VADD(Tb, Tg), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 5)]), VSUB(Tg, Tb), ovs, &(xo[WS(os, 1)]));
	       Tp = VADD(Tj, Tk);
	       Tq = VADD(Tm, Tn);
	       ST(&(xo[WS(os, 4)]), VSUB(Tp, Tq), ovs, &(xo[0]));
	       ST(&(xo[0]), VADD(Tp, Tq), ovs, &(xo[0]));
	  }
	  {
	       V Th, Ti, Tl, To;
	       Th = VBYI(VADD(Ta, T7));
	       Ti = VADD(Te, Tf);
	       ST(&(xo[WS(os, 1)]), VADD(Th, Ti), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 7)]), VSUB(Ti, Th), ovs, &(xo[WS(os, 1)]));
	       Tl = VSUB(Tj, Tk);
	       To = VBYI(VSUB(Tm, Tn));
	       ST(&(xo[WS(os, 6)]), VSUB(Tl, To), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 2)]), VADD(Tl, To), ovs, &(xo[0]));
	  }
     }
}

static const kdft_desc desc = { 8, "n1bv_8", {26, 2, 0, 0}, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1bv_8) (planner *p) {
     X(kdft_register) (p, n1bv_8, &desc);
}

#endif				/* HAVE_FMA */
