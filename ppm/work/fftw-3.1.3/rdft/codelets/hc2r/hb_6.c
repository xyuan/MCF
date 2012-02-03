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
/* Generated on Sat Oct  4 10:35:31 EDT 2008 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 6 -dif -name hb_6 -include hb.h */

/*
 * This function contains 46 FP additions, 32 FP multiplications,
 * (or, 24 additions, 10 multiplications, 22 fused multiply/add),
 * 47 stack variables, and 24 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_hc2hc.ml,v 1.16 2006-02-12 23:34:12 athena Exp $
 */

#include "hb.h"

static const R *hb_6(R *rio, R *iio, const R *W, stride ios, INT m, INT dist)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     INT i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 10, MAKE_VOLATILE_STRIDE(ios)) {
	  E Tk, Tt, Tz, Tv, Tb, TA, Tm, Tl, Tu;
	  {
	       E Tp, TR, Tj, Tq, TN, TV, T3, TC, T7, T8, T4, T5;
	       {
		    E TJ, TK, Ti, Tf, TL, Td, Te, T1, T2, TM;
		    {
			 E Tn, To, Tg, Th;
			 Tn = iio[0];
			 To = rio[WS(ios, 3)];
			 Tg = iio[-WS(ios, 2)];
			 Th = rio[WS(ios, 5)];
			 Td = iio[-WS(ios, 1)];
			 TJ = Tn + To;
			 Tp = Tn - To;
			 Te = rio[WS(ios, 4)];
			 TK = Tg + Th;
			 Ti = Tg - Th;
		    }
		    Tf = Td - Te;
		    TL = Te + Td;
		    T1 = rio[0];
		    T2 = iio[-WS(ios, 3)];
		    TR = TL + TK;
		    TM = TK - TL;
		    Tj = Tf - Ti;
		    Tq = Tf + Ti;
		    TN = TJ + TM;
		    TV = FNMS(KP500000000, TM, TJ);
		    T3 = T1 + T2;
		    TC = T1 - T2;
		    T7 = iio[-WS(ios, 4)];
		    T8 = rio[WS(ios, 1)];
		    T4 = rio[WS(ios, 2)];
		    T5 = iio[-WS(ios, 5)];
	       }
	       {
		    E TZ, T12, Ts, TG, T10, TX, Tc, TS, T13, T11, TP, TU, T14;
		    iio[-WS(ios, 5)] = Tp + Tq;
		    {
			 E T9, TE, T6, TD;
			 T9 = T7 + T8;
			 TE = T7 - T8;
			 T6 = T4 + T5;
			 TD = T4 - T5;
			 TZ = W[8];
			 T12 = W[9];
			 {
			      E TW, TF, Ta, TQ;
			      TW = TD - TE;
			      TF = TD + TE;
			      Ts = T6 - T9;
			      Ta = T6 + T9;
			      TG = TC + TF;
			      TQ = FNMS(KP500000000, TF, TC);
			      T10 = FNMS(KP866025403, TW, TV);
			      TX = FMA(KP866025403, TW, TV);
			      rio[0] = T3 + Ta;
			      Tc = FNMS(KP500000000, Ta, T3);
			      TS = FNMS(KP866025403, TR, TQ);
			      T13 = FMA(KP866025403, TR, TQ);
			      T11 = TZ * T10;
			 }
		    }
		    T14 = TZ * T13;
		    iio[0] = FMA(T12, T13, T11);
		    TP = W[0];
		    TU = W[1];
		    rio[WS(ios, 5)] = FNMS(T12, T10, T14);
		    {
			 E TB, TI, TH, TY, TT;
			 TY = TP * TX;
			 TT = TP * TS;
			 TB = W[4];
			 iio[-WS(ios, 4)] = FMA(TU, TS, TY);
			 rio[WS(ios, 1)] = FNMS(TU, TX, TT);
			 TI = W[5];
			 TH = TB * TG;
			 {
			      E Ty, Tx, Tr, Tw, TO;
			      Tr = FNMS(KP500000000, Tq, Tp);
			      Tw = FNMS(KP866025403, Tj, Tc);
			      Tk = FMA(KP866025403, Tj, Tc);
			      TO = TI * TG;
			      rio[WS(ios, 3)] = FNMS(TI, TN, TH);
			      Tt = FMA(KP866025403, Ts, Tr);
			      Tz = FNMS(KP866025403, Ts, Tr);
			      iio[-WS(ios, 2)] = FMA(TB, TN, TO);
			      Tv = W[2];
			      Ty = W[3];
			      Tb = W[6];
			      Tx = Tv * Tw;
			      TA = Ty * Tw;
			      Tm = W[7];
			      Tl = Tb * Tk;
			      rio[WS(ios, 2)] = FNMS(Ty, Tz, Tx);
			 }
		    }
	       }
	  }
	  iio[-WS(ios, 3)] = FMA(Tv, Tz, TA);
	  Tu = Tm * Tk;
	  rio[WS(ios, 4)] = FNMS(Tm, Tt, Tl);
	  iio[-WS(ios, 1)] = FMA(Tb, Tt, Tu);
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 6},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 6, "hb_6", twinstr, &GENUS, {24, 10, 22, 0}, 0, 0, 0 };

void X(codelet_hb_6) (planner *p) {
     X(khc2hc_register) (p, hb_6, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc -compact -variables 4 -pipeline-latency 4 -sign 1 -n 6 -dif -name hb_6 -include hb.h */

/*
 * This function contains 46 FP additions, 28 FP multiplications,
 * (or, 32 additions, 14 multiplications, 14 fused multiply/add),
 * 25 stack variables, and 24 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_hc2hc.ml,v 1.16 2006-02-12 23:34:12 athena Exp $
 */

#include "hb.h"

static const R *hb_6(R *rio, R *iio, const R *W, stride ios, INT m, INT dist)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     INT i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 10, MAKE_VOLATILE_STRIDE(ios)) {
	  E T3, Ty, Tp, TE, Ta, TO, Tm, TB, Tj, TL, Tq, TH;
	  {
	       E T1, T2, Tn, To;
	       T1 = rio[0];
	       T2 = iio[-WS(ios, 3)];
	       T3 = T1 + T2;
	       Ty = T1 - T2;
	       Tn = iio[0];
	       To = rio[WS(ios, 3)];
	       Tp = Tn - To;
	       TE = Tn + To;
	  }
	  {
	       E T6, Tz, T9, TA;
	       {
		    E T4, T5, T7, T8;
		    T4 = rio[WS(ios, 2)];
		    T5 = iio[-WS(ios, 5)];
		    T6 = T4 + T5;
		    Tz = T4 - T5;
		    T7 = iio[-WS(ios, 4)];
		    T8 = rio[WS(ios, 1)];
		    T9 = T7 + T8;
		    TA = T7 - T8;
	       }
	       Ta = T6 + T9;
	       TO = KP866025403 * (Tz - TA);
	       Tm = KP866025403 * (T6 - T9);
	       TB = Tz + TA;
	  }
	  {
	       E Tf, TF, Ti, TG;
	       {
		    E Td, Te, Tg, Th;
		    Td = iio[-WS(ios, 1)];
		    Te = rio[WS(ios, 4)];
		    Tf = Td - Te;
		    TF = Te + Td;
		    Tg = iio[-WS(ios, 2)];
		    Th = rio[WS(ios, 5)];
		    Ti = Tg - Th;
		    TG = Tg + Th;
	       }
	       Tj = KP866025403 * (Tf - Ti);
	       TL = KP866025403 * (TF + TG);
	       Tq = Tf + Ti;
	       TH = TF - TG;
	  }
	  rio[0] = T3 + Ta;
	  iio[-WS(ios, 5)] = Tp + Tq;
	  {
	       E TC, TI, Tx, TD;
	       TC = Ty + TB;
	       TI = TE - TH;
	       Tx = W[4];
	       TD = W[5];
	       rio[WS(ios, 3)] = FNMS(TD, TI, Tx * TC);
	       iio[-WS(ios, 2)] = FMA(TD, TC, Tx * TI);
	  }
	  {
	       E Tk, Tu, Ts, Tw, Tc, Tr;
	       Tc = FNMS(KP500000000, Ta, T3);
	       Tk = Tc + Tj;
	       Tu = Tc - Tj;
	       Tr = FNMS(KP500000000, Tq, Tp);
	       Ts = Tm + Tr;
	       Tw = Tr - Tm;
	       {
		    E Tb, Tl, Tt, Tv;
		    Tb = W[6];
		    Tl = W[7];
		    rio[WS(ios, 4)] = FNMS(Tl, Ts, Tb * Tk);
		    iio[-WS(ios, 1)] = FMA(Tl, Tk, Tb * Ts);
		    Tt = W[2];
		    Tv = W[3];
		    rio[WS(ios, 2)] = FNMS(Tv, Tw, Tt * Tu);
		    iio[-WS(ios, 3)] = FMA(Tv, Tu, Tt * Tw);
	       }
	  }
	  {
	       E TM, TU, TQ, TS, TK, TP;
	       TK = FNMS(KP500000000, TB, Ty);
	       TM = TK - TL;
	       TU = TK + TL;
	       TP = FMA(KP500000000, TH, TE);
	       TQ = TO + TP;
	       TS = TP - TO;
	       {
		    E TJ, TN, TR, TT;
		    TJ = W[0];
		    TN = W[1];
		    rio[WS(ios, 1)] = FNMS(TN, TQ, TJ * TM);
		    iio[-WS(ios, 4)] = FMA(TJ, TQ, TN * TM);
		    TR = W[8];
		    TT = W[9];
		    iio[0] = FMA(TR, TS, TT * TU);
		    rio[WS(ios, 5)] = FNMS(TT, TS, TR * TU);
	       }
	  }
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 6},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 6, "hb_6", twinstr, &GENUS, {32, 14, 14, 0}, 0, 0, 0 };

void X(codelet_hb_6) (planner *p) {
     X(khc2hc_register) (p, hb_6, &desc);
}
#endif				/* HAVE_FMA */
