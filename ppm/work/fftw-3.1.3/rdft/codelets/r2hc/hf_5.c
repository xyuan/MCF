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
/* Generated on Sat Oct  4 10:30:53 EDT 2008 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 5 -dit -name hf_5 -include hf.h */

/*
 * This function contains 40 FP additions, 34 FP multiplications,
 * (or, 14 additions, 8 multiplications, 26 fused multiply/add),
 * 36 stack variables, and 20 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_hc2hc.ml,v 1.16 2006-02-12 23:34:12 athena Exp $
 */

#include "hf.h"

static const R *hf_5(R *rio, R *iio, const R *W, stride ios, INT m, INT dist)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     INT i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 8, MAKE_VOLATILE_STRIDE(ios)) {
	  E T1, TM, TA, TJ, Te, TQ, TC, Tk, TE, Tq;
	  {
	       E Tm, Tp, TD, Tn, To;
	       {
		    E T9, Tc, Ty, Ta, Tb, Tx, T7, Tz, Td;
		    T1 = rio[0];
		    {
			 E T3, T6, T8, Tw, T4, T2, T5;
			 T3 = rio[WS(ios, 1)];
			 T6 = iio[-WS(ios, 3)];
			 T2 = W[0];
			 T9 = rio[WS(ios, 4)];
			 Tc = iio[0];
			 T8 = W[6];
			 Tw = T2 * T6;
			 T4 = T2 * T3;
			 T5 = W[1];
			 Ty = T8 * Tc;
			 Ta = T8 * T9;
			 Tb = W[7];
			 Tx = FNMS(T5, T3, Tw);
			 T7 = FMA(T5, T6, T4);
		    }
		    TM = iio[-WS(ios, 4)];
		    Tz = FNMS(Tb, T9, Ty);
		    Td = FMA(Tb, Tc, Ta);
		    {
			 E Tg, Tj, Tl, TB, Th, Tf, Ti;
			 Tg = rio[WS(ios, 2)];
			 Tj = iio[-WS(ios, 2)];
			 TA = Tx - Tz;
			 TJ = Tx + Tz;
			 Te = T7 + Td;
			 TQ = Td - T7;
			 Tf = W[2];
			 Tm = rio[WS(ios, 3)];
			 Tp = iio[-WS(ios, 1)];
			 Tl = W[4];
			 TB = Tf * Tj;
			 Th = Tf * Tg;
			 Ti = W[3];
			 TD = Tl * Tp;
			 Tn = Tl * Tm;
			 To = W[5];
			 TC = FNMS(Ti, Tg, TB);
			 Tk = FMA(Ti, Tj, Th);
		    }
	       }
	       TE = FNMS(To, Tm, TD);
	       Tq = FMA(To, Tp, Tn);
	  }
	  {
	       E TG, TI, TO, TS, TU, Tu, TN, Tt, TK, TF;
	       TK = TC + TE;
	       TF = TC - TE;
	       {
		    E Tr, TR, TL, Ts;
		    Tr = Tk + Tq;
		    TR = Tk - Tq;
		    TG = FMA(KP618033988, TF, TA);
		    TI = FNMS(KP618033988, TA, TF);
		    TO = TJ - TK;
		    TL = TJ + TK;
		    TS = FNMS(KP618033988, TR, TQ);
		    TU = FMA(KP618033988, TQ, TR);
		    Tu = Te - Tr;
		    Ts = Te + Tr;
		    iio[0] = TL + TM;
		    TN = FNMS(KP250000000, TL, TM);
		    rio[0] = T1 + Ts;
		    Tt = FNMS(KP250000000, Ts, T1);
	       }
	       {
		    E TT, TP, TH, Tv;
		    TT = FNMS(KP559016994, TO, TN);
		    TP = FMA(KP559016994, TO, TN);
		    TH = FNMS(KP559016994, Tu, Tt);
		    Tv = FMA(KP559016994, Tu, Tt);
		    iio[-WS(ios, 1)] = FMA(KP951056516, TS, TP);
		    rio[WS(ios, 4)] = FMS(KP951056516, TS, TP);
		    iio[-WS(ios, 2)] = FMA(KP951056516, TU, TT);
		    rio[WS(ios, 3)] = FMS(KP951056516, TU, TT);
		    rio[WS(ios, 1)] = FMA(KP951056516, TG, Tv);
		    iio[-WS(ios, 4)] = FNMS(KP951056516, TG, Tv);
		    iio[-WS(ios, 3)] = FMA(KP951056516, TI, TH);
		    rio[WS(ios, 2)] = FNMS(KP951056516, TI, TH);
	       }
	  }
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 5},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 5, "hf_5", twinstr, &GENUS, {14, 8, 26, 0}, 0, 0, 0 };

void X(codelet_hf_5) (planner *p) {
     X(khc2hc_register) (p, hf_5, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc -compact -variables 4 -pipeline-latency 4 -n 5 -dit -name hf_5 -include hf.h */

/*
 * This function contains 40 FP additions, 28 FP multiplications,
 * (or, 26 additions, 14 multiplications, 14 fused multiply/add),
 * 29 stack variables, and 20 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_hc2hc.ml,v 1.16 2006-02-12 23:34:12 athena Exp $
 */

#include "hf.h"

static const R *hf_5(R *rio, R *iio, const R *W, stride ios, INT m, INT dist)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     INT i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 8, MAKE_VOLATILE_STRIDE(ios)) {
	  E T1, TE, Tu, Tx, TG, TF, TB, TC, TD, Tc, Tn, To;
	  T1 = rio[0];
	  TE = iio[-WS(ios, 4)];
	  {
	       E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
	       {
		    E T3, T5, T2, T4;
		    T3 = rio[WS(ios, 1)];
		    T5 = iio[-WS(ios, 3)];
		    T2 = W[0];
		    T4 = W[1];
		    T6 = FMA(T2, T3, T4 * T5);
		    Ts = FNMS(T4, T3, T2 * T5);
	       }
	       {
		    E Tj, Tl, Ti, Tk;
		    Tj = rio[WS(ios, 3)];
		    Tl = iio[-WS(ios, 1)];
		    Ti = W[4];
		    Tk = W[5];
		    Tm = FMA(Ti, Tj, Tk * Tl);
		    Tw = FNMS(Tk, Tj, Ti * Tl);
	       }
	       {
		    E T8, Ta, T7, T9;
		    T8 = rio[WS(ios, 4)];
		    Ta = iio[0];
		    T7 = W[6];
		    T9 = W[7];
		    Tb = FMA(T7, T8, T9 * Ta);
		    Tt = FNMS(T9, T8, T7 * Ta);
	       }
	       {
		    E Te, Tg, Td, Tf;
		    Te = rio[WS(ios, 2)];
		    Tg = iio[-WS(ios, 2)];
		    Td = W[2];
		    Tf = W[3];
		    Th = FMA(Td, Te, Tf * Tg);
		    Tv = FNMS(Tf, Te, Td * Tg);
	       }
	       Tu = Ts - Tt;
	       Tx = Tv - Tw;
	       TG = Th - Tm;
	       TF = Tb - T6;
	       TB = Ts + Tt;
	       TC = Tv + Tw;
	       TD = TB + TC;
	       Tc = T6 + Tb;
	       Tn = Th + Tm;
	       To = Tc + Tn;
	  }
	  rio[0] = T1 + To;
	  iio[0] = TD + TE;
	  {
	       E Ty, TA, Tr, Tz, Tp, Tq;
	       Ty = FMA(KP951056516, Tu, KP587785252 * Tx);
	       TA = FNMS(KP587785252, Tu, KP951056516 * Tx);
	       Tp = KP559016994 * (Tc - Tn);
	       Tq = FNMS(KP250000000, To, T1);
	       Tr = Tp + Tq;
	       Tz = Tq - Tp;
	       iio[-WS(ios, 4)] = Tr - Ty;
	       iio[-WS(ios, 3)] = Tz + TA;
	       rio[WS(ios, 1)] = Tr + Ty;
	       rio[WS(ios, 2)] = Tz - TA;
	  }
	  {
	       E TH, TL, TK, TM, TI, TJ;
	       TH = FNMS(KP587785252, TG, KP951056516 * TF);
	       TL = FMA(KP587785252, TF, KP951056516 * TG);
	       TI = KP559016994 * (TB - TC);
	       TJ = FNMS(KP250000000, TD, TE);
	       TK = TI + TJ;
	       TM = TJ - TI;
	       rio[WS(ios, 4)] = TH - TK;
	       iio[-WS(ios, 2)] = TL + TM;
	       iio[-WS(ios, 1)] = TH + TK;
	       rio[WS(ios, 3)] = TL - TM;
	  }
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 5},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 5, "hf_5", twinstr, &GENUS, {26, 14, 14, 0}, 0, 0, 0 };

void X(codelet_hf_5) (planner *p) {
     X(khc2hc_register) (p, hf_5, &desc);
}
#endif				/* HAVE_FMA */