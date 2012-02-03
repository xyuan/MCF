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
/* Generated on Sat Oct  4 10:25:22 EDT 2008 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 14 -name n1fv_14 -include n1f.h */

/*
 * This function contains 74 FP additions, 48 FP multiplications,
 * (or, 32 additions, 6 multiplications, 42 fused multiply/add),
 * 63 stack variables, and 28 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_notw_c.ml,v 1.17 2006-02-12 23:34:12 athena Exp $
 */

#include "n1f.h"

static void n1fv_14(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP801937735, +0.801937735804838252472204639014890102331838324);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP692021471, +0.692021471630095869627814897002069140197260599);
     DVK(KP554958132, +0.554958132087371191422194871006410481067288862);
     DVK(KP356895867, +0.356895867892209443894399510021300583399127187);
     INT i;
     const R *xi;
     R *xo;
     xi = ri;
     xo = ro;
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	  V TH, T3, TP, Tn, Ta, Ts, TW, TK, TO, Tk, TM, Tg, TL, Td, T1;
	  V T2;
	  T1 = LD(&(xi[0]), ivs, &(xi[0]));
	  T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	  {
	       V Ti, TI, T6, TJ, T9, Tj, Te, Tf, Tb, Tc;
	       {
		    V T4, T5, T7, T8, Tl, Tm;
		    T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T5 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    T7 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    Tl = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    Tm = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    Ti = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    TH = VADD(T1, T2);
		    T3 = VSUB(T1, T2);
		    TI = VADD(T4, T5);
		    T6 = VSUB(T4, T5);
		    TJ = VADD(T7, T8);
		    T9 = VSUB(T7, T8);
		    TP = VADD(Tl, Tm);
		    Tn = VSUB(Tl, Tm);
		    Tj = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
		    Te = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    Tf = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    Tc = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
	       }
	       Ta = VADD(T6, T9);
	       Ts = VSUB(T9, T6);
	       TW = VSUB(TJ, TI);
	       TK = VADD(TI, TJ);
	       TO = VADD(Ti, Tj);
	       Tk = VSUB(Ti, Tj);
	       TM = VADD(Te, Tf);
	       Tg = VSUB(Te, Tf);
	       TL = VADD(Tb, Tc);
	       Td = VSUB(Tb, Tc);
	  }
	  {
	       V T18, TB, T13, TY, TG, Tw, T11, Tr, T16, TT, Tz, TE, TU, TQ;
	       TU = VSUB(TO, TP);
	       TQ = VADD(TO, TP);
	       {
		    V Tt, To, TV, TN;
		    Tt = VSUB(Tn, Tk);
		    To = VADD(Tk, Tn);
		    TV = VSUB(TL, TM);
		    TN = VADD(TL, TM);
		    {
			 V Tu, Th, TZ, T17;
			 Tu = VSUB(Tg, Td);
			 Th = VADD(Td, Tg);
			 TZ = VFNMS(LDK(KP356895867), TK, TQ);
			 T17 = VFNMS(LDK(KP554958132), TU, TW);
			 {
			      V Tp, TA, T14, TR;
			      Tp = VFNMS(LDK(KP356895867), Ta, To);
			      TA = VFMA(LDK(KP554958132), Tt, Ts);
			      ST(&(xo[0]), VADD(TH, VADD(TK, VADD(TN, TQ))), ovs, &(xo[0]));
			      T14 = VFNMS(LDK(KP356895867), TN, TK);
			      TR = VFNMS(LDK(KP356895867), TQ, TN);
			      {
				   V T12, TX, Tx, TC;
				   T12 = VFMA(LDK(KP554958132), TV, TU);
				   TX = VFMA(LDK(KP554958132), TW, TV);
				   ST(&(xo[WS(os, 7)]), VADD(T3, VADD(Ta, VADD(Th, To))), ovs, &(xo[WS(os, 1)]));
				   Tx = VFNMS(LDK(KP356895867), Th, Ta);
				   TC = VFNMS(LDK(KP356895867), To, Th);
				   {
					V TF, Tv, T10, Tq;
					TF = VFNMS(LDK(KP554958132), Ts, Tu);
					Tv = VFMA(LDK(KP554958132), Tu, Tt);
					T10 = VFNMS(LDK(KP692021471), TZ, TN);
					T18 = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), T17, TV));
					Tq = VFNMS(LDK(KP692021471), Tp, Th);
					TB = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), TA, Tu));
					{
					     V T15, TS, Ty, TD;
					     T15 = VFNMS(LDK(KP692021471), T14, TQ);
					     TS = VFNMS(LDK(KP692021471), TR, TK);
					     T13 = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), T12, TW));
					     TY = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), TX, TU));
					     Ty = VFNMS(LDK(KP692021471), Tx, To);
					     TD = VFNMS(LDK(KP692021471), TC, Ta);
					     TG = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), TF, Tt));
					     Tw = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Tv, Ts));
					     T11 = VFNMS(LDK(KP900968867), T10, TH);
					     Tr = VFNMS(LDK(KP900968867), Tq, T3);
					     T16 = VFNMS(LDK(KP900968867), T15, TH);
					     TT = VFNMS(LDK(KP900968867), TS, TH);
					     Tz = VFNMS(LDK(KP900968867), Ty, T3);
					     TE = VFNMS(LDK(KP900968867), TD, T3);
					}
				   }
			      }
			 }
		    }
	       }
	       ST(&(xo[WS(os, 12)]), VFNMSI(T13, T11), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 2)]), VFMAI(T13, T11), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 9)]), VFMAI(Tw, Tr), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 5)]), VFNMSI(Tw, Tr), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 8)]), VFNMSI(T18, T16), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 6)]), VFMAI(T18, T16), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 10)]), VFNMSI(TY, TT), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 4)]), VFMAI(TY, TT), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 1)]), VFMAI(TB, Tz), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 13)]), VFNMSI(TB, Tz), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 3)]), VFMAI(TG, TE), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 11)]), VFNMSI(TG, TE), ovs, &(xo[WS(os, 1)]));
	  }
     }
}

static const kdft_desc desc = { 14, "n1fv_14", {32, 6, 42, 0}, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1fv_14) (planner *p) {
     X(kdft_register) (p, n1fv_14, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c -simd -compact -variables 4 -pipeline-latency 8 -n 14 -name n1fv_14 -include n1f.h */

/*
 * This function contains 74 FP additions, 36 FP multiplications,
 * (or, 50 additions, 12 multiplications, 24 fused multiply/add),
 * 33 stack variables, and 28 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_notw_c.ml,v 1.17 2006-02-12 23:34:12 athena Exp $
 */

#include "n1f.h"

static void n1fv_14(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP222520933, +0.222520933956314404288902564496794759466355569);
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP623489801, +0.623489801858733530525004884004239810632274731);
     DVK(KP433883739, +0.433883739117558120475768332848358754609990728);
     DVK(KP781831482, +0.781831482468029808708444526674057750232334519);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     INT i;
     const R *xi;
     R *xo;
     xi = ri;
     xo = ro;
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	  V T3, Ty, To, TK, Tr, TE, Ta, TJ, Tq, TB, Th, TL, Ts, TH, T1;
	  V T2;
	  T1 = LD(&(xi[0]), ivs, &(xi[0]));
	  T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	  T3 = VSUB(T1, T2);
	  Ty = VADD(T1, T2);
	  {
	       V Tk, TC, Tn, TD;
	       {
		    V Ti, Tj, Tl, Tm;
		    Ti = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    Tj = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
		    Tk = VSUB(Ti, Tj);
		    TC = VADD(Ti, Tj);
		    Tl = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    Tm = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    Tn = VSUB(Tl, Tm);
		    TD = VADD(Tl, Tm);
	       }
	       To = VADD(Tk, Tn);
	       TK = VSUB(TC, TD);
	       Tr = VSUB(Tn, Tk);
	       TE = VADD(TC, TD);
	  }
	  {
	       V T6, Tz, T9, TA;
	       {
		    V T4, T5, T7, T8;
		    T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T5 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    T6 = VSUB(T4, T5);
		    Tz = VADD(T4, T5);
		    T7 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    T9 = VSUB(T7, T8);
		    TA = VADD(T7, T8);
	       }
	       Ta = VADD(T6, T9);
	       TJ = VSUB(TA, Tz);
	       Tq = VSUB(T9, T6);
	       TB = VADD(Tz, TA);
	  }
	  {
	       V Td, TF, Tg, TG;
	       {
		    V Tb, Tc, Te, Tf;
		    Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    Tc = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
		    Td = VSUB(Tb, Tc);
		    TF = VADD(Tb, Tc);
		    Te = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    Tf = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    Tg = VSUB(Te, Tf);
		    TG = VADD(Te, Tf);
	       }
	       Th = VADD(Td, Tg);
	       TL = VSUB(TF, TG);
	       Ts = VSUB(Tg, Td);
	       TH = VADD(TF, TG);
	  }
	  ST(&(xo[WS(os, 7)]), VADD(T3, VADD(Ta, VADD(Th, To))), ovs, &(xo[WS(os, 1)]));
	  ST(&(xo[0]), VADD(Ty, VADD(TB, VADD(TH, TE))), ovs, &(xo[0]));
	  {
	       V Tt, Tp, TP, TQ;
	       Tt = VBYI(VFNMS(LDK(KP781831482), Tr, VFNMS(LDK(KP433883739), Ts, VMUL(LDK(KP974927912), Tq))));
	       Tp = VFMA(LDK(KP623489801), To, VFNMS(LDK(KP900968867), Th, VFNMS(LDK(KP222520933), Ta, T3)));
	       ST(&(xo[WS(os, 5)]), VSUB(Tp, Tt), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 9)]), VADD(Tp, Tt), ovs, &(xo[WS(os, 1)]));
	       TP = VBYI(VFMA(LDK(KP974927912), TJ, VFMA(LDK(KP433883739), TL, VMUL(LDK(KP781831482), TK))));
	       TQ = VFMA(LDK(KP623489801), TE, VFNMS(LDK(KP900968867), TH, VFNMS(LDK(KP222520933), TB, Ty)));
	       ST(&(xo[WS(os, 2)]), VADD(TP, TQ), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 12)]), VSUB(TQ, TP), ovs, &(xo[0]));
	  }
	  {
	       V Tv, Tu, TM, TI;
	       Tv = VBYI(VFMA(LDK(KP781831482), Tq, VFMA(LDK(KP974927912), Ts, VMUL(LDK(KP433883739), Tr))));
	       Tu = VFMA(LDK(KP623489801), Ta, VFNMS(LDK(KP900968867), To, VFNMS(LDK(KP222520933), Th, T3)));
	       ST(&(xo[WS(os, 13)]), VSUB(Tu, Tv), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 1)]), VADD(Tu, Tv), ovs, &(xo[WS(os, 1)]));
	       TM = VBYI(VFNMS(LDK(KP433883739), TK, VFNMS(LDK(KP974927912), TL, VMUL(LDK(KP781831482), TJ))));
	       TI = VFMA(LDK(KP623489801), TB, VFNMS(LDK(KP900968867), TE, VFNMS(LDK(KP222520933), TH, Ty)));
	       ST(&(xo[WS(os, 6)]), VSUB(TI, TM), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 8)]), VADD(TM, TI), ovs, &(xo[0]));
	  }
	  {
	       V TO, TN, Tx, Tw;
	       TO = VBYI(VFMA(LDK(KP433883739), TJ, VFNMS(LDK(KP974927912), TK, VMUL(LDK(KP781831482), TL))));
	       TN = VFMA(LDK(KP623489801), TH, VFNMS(LDK(KP222520933), TE, VFNMS(LDK(KP900968867), TB, Ty)));
	       ST(&(xo[WS(os, 4)]), VSUB(TN, TO), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 10)]), VADD(TO, TN), ovs, &(xo[0]));
	       Tx = VBYI(VFMA(LDK(KP433883739), Tq, VFNMS(LDK(KP781831482), Ts, VMUL(LDK(KP974927912), Tr))));
	       Tw = VFMA(LDK(KP623489801), Th, VFNMS(LDK(KP222520933), To, VFNMS(LDK(KP900968867), Ta, T3)));
	       ST(&(xo[WS(os, 11)]), VSUB(Tw, Tx), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 3)]), VADD(Tw, Tx), ovs, &(xo[WS(os, 1)]));
	  }
     }
}

static const kdft_desc desc = { 14, "n1fv_14", {50, 12, 24, 0}, &GENUS, 0, 0, 0, 0 };

void X(codelet_n1fv_14) (planner *p) {
     X(kdft_register) (p, n1fv_14, &desc);
}

#endif				/* HAVE_FMA */
