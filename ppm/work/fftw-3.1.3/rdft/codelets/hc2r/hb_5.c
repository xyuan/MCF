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

/* Generated by: ../../../genfft/gen_hc2hc -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 5 -dif -name hb_5 -include hb.h */

/*
 * This function contains 40 FP additions, 34 FP multiplications,
 * (or, 14 additions, 8 multiplications, 26 fused multiply/add),
 * 46 stack variables, and 20 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_hc2hc.ml,v 1.16 2006-02-12 23:34:12 athena Exp $
 */

#include "hb.h"

static const R *hb_5(R *rio, R *iio, const R *W, stride ios, INT m, INT dist)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     INT i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 8, MAKE_VOLATILE_STRIDE(ios)) {
	  E TQ, TP, TT, TR, TS, TU;
	  {
	       E T1, Tn, TM, Tw, Tb, T8, Tp, Ti, Ta, Td, Te;
	       {
		    E T5, T6, T2, T3, T7, Tv;
		    T1 = rio[0];
		    T5 = rio[WS(ios, 2)];
		    T6 = iio[-WS(ios, 3)];
		    T2 = rio[WS(ios, 1)];
		    T3 = iio[-WS(ios, 4)];
		    Tn = iio[0];
		    T7 = T5 + T6;
		    Tv = T5 - T6;
		    {
			 E T4, Tu, Tg, Th;
			 T4 = T2 + T3;
			 Tu = T2 - T3;
			 Tg = iio[-WS(ios, 2)];
			 Th = rio[WS(ios, 3)];
			 TM = FNMS(KP618033988, Tu, Tv);
			 Tw = FMA(KP618033988, Tv, Tu);
			 Tb = T4 - T7;
			 T8 = T4 + T7;
			 Tp = Tg - Th;
			 Ti = Tg + Th;
			 Ta = FNMS(KP250000000, T8, T1);
			 Td = iio[-WS(ios, 1)];
			 Te = rio[WS(ios, 4)];
		    }
	       }
	       {
		    E TG, Tc, T9, Tm, Tz, Ts, Tq, Tj, TH, Tr, TC, Tf, To;
		    rio[0] = T1 + T8;
		    TG = FNMS(KP559016994, Tb, Ta);
		    Tc = FMA(KP559016994, Tb, Ta);
		    T9 = W[6];
		    Tf = Td + Te;
		    To = Td - Te;
		    Tm = W[7];
		    Tz = W[0];
		    Ts = To - Tp;
		    Tq = To + Tp;
		    Tj = FMA(KP618033988, Ti, Tf);
		    TH = FNMS(KP618033988, Tf, Ti);
		    Tr = FNMS(KP250000000, Tq, Tn);
		    TC = W[1];
		    iio[-WS(ios, 4)] = Tn + Tq;
		    {
			 E TA, Tk, Tt, TL, TI;
			 TA = FNMS(KP951056516, Tj, Tc);
			 Tk = FMA(KP951056516, Tj, Tc);
			 Tt = FMA(KP559016994, Ts, Tr);
			 TL = FNMS(KP559016994, Ts, Tr);
			 {
			      E TE, TB, Ty, Tl, TD, Tx;
			      TE = TC * TA;
			      TB = Tz * TA;
			      Ty = Tm * Tk;
			      Tl = T9 * Tk;
			      TD = FMA(KP951056516, Tw, Tt);
			      Tx = FNMS(KP951056516, Tw, Tt);
			      TI = FNMS(KP951056516, TH, TG);
			      TQ = FMA(KP951056516, TH, TG);
			      iio[-WS(ios, 3)] = FMA(Tz, TD, TE);
			      rio[WS(ios, 1)] = FNMS(TC, TD, TB);
			      iio[0] = FMA(T9, Tx, Ty);
			      rio[WS(ios, 4)] = FNMS(Tm, Tx, Tl);
			 }
			 {
			      E TF, TK, TN, TJ, TO;
			      TF = W[4];
			      TK = W[5];
			      TP = W[2];
			      TT = FNMS(KP951056516, TM, TL);
			      TN = FMA(KP951056516, TM, TL);
			      TJ = TF * TI;
			      TO = TK * TI;
			      TR = TP * TQ;
			      TS = W[3];
			      rio[WS(ios, 3)] = FNMS(TK, TN, TJ);
			      iio[-WS(ios, 1)] = FMA(TF, TN, TO);
			 }
		    }
	       }
	  }
	  rio[WS(ios, 2)] = FNMS(TS, TT, TR);
	  TU = TS * TQ;
	  iio[-WS(ios, 2)] = FMA(TP, TT, TU);
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 5},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 5, "hb_5", twinstr, &GENUS, {14, 8, 26, 0}, 0, 0, 0 };

void X(codelet_hb_5) (planner *p) {
     X(khc2hc_register) (p, hb_5, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc -compact -variables 4 -pipeline-latency 4 -sign 1 -n 5 -dif -name hb_5 -include hb.h */

/*
 * This function contains 40 FP additions, 28 FP multiplications,
 * (or, 26 additions, 14 multiplications, 14 fused multiply/add),
 * 27 stack variables, and 20 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: algsimp.ml,v 1.9 2006-02-12 23:34:12 athena Exp $
 * $Id: fft.ml,v 1.4 2006-01-05 03:04:27 stevenj Exp $
 * $Id: gen_hc2hc.ml,v 1.16 2006-02-12 23:34:12 athena Exp $
 */

#include "hb.h"

static const R *hb_5(R *rio, R *iio, const R *W, stride ios, INT m, INT dist)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     INT i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 8, MAKE_VOLATILE_STRIDE(ios)) {
	  E T1, Tj, TG, Ts, T8, Ti, T9, Tn, TD, Tu, Tg, Tt;
	  {
	       E T7, Tr, T4, Tq;
	       T1 = rio[0];
	       {
		    E T5, T6, T2, T3;
		    T5 = rio[WS(ios, 2)];
		    T6 = iio[-WS(ios, 3)];
		    T7 = T5 + T6;
		    Tr = T5 - T6;
		    T2 = rio[WS(ios, 1)];
		    T3 = iio[-WS(ios, 4)];
		    T4 = T2 + T3;
		    Tq = T2 - T3;
	       }
	       Tj = KP559016994 * (T4 - T7);
	       TG = FMA(KP951056516, Tq, KP587785252 * Tr);
	       Ts = FNMS(KP951056516, Tr, KP587785252 * Tq);
	       T8 = T4 + T7;
	       Ti = FNMS(KP250000000, T8, T1);
	  }
	  {
	       E Tf, Tm, Tc, Tl;
	       T9 = iio[0];
	       {
		    E Td, Te, Ta, Tb;
		    Td = iio[-WS(ios, 2)];
		    Te = rio[WS(ios, 3)];
		    Tf = Td - Te;
		    Tm = Td + Te;
		    Ta = iio[-WS(ios, 1)];
		    Tb = rio[WS(ios, 4)];
		    Tc = Ta - Tb;
		    Tl = Ta + Tb;
	       }
	       Tn = FNMS(KP951056516, Tm, KP587785252 * Tl);
	       TD = FMA(KP951056516, Tl, KP587785252 * Tm);
	       Tu = KP559016994 * (Tc - Tf);
	       Tg = Tc + Tf;
	       Tt = FNMS(KP250000000, Tg, T9);
	  }
	  rio[0] = T1 + T8;
	  iio[-WS(ios, 4)] = T9 + Tg;
	  {
	       E TE, TM, TI, TK, TC, TH;
	       TC = Tj + Ti;
	       TE = TC - TD;
	       TM = TC + TD;
	       TH = Tu + Tt;
	       TI = TG + TH;
	       TK = TH - TG;
	       {
		    E TB, TF, TJ, TL;
		    TB = W[0];
		    TF = W[1];
		    rio[WS(ios, 1)] = FNMS(TF, TI, TB * TE);
		    iio[-WS(ios, 3)] = FMA(TB, TI, TF * TE);
		    TJ = W[6];
		    TL = W[7];
		    iio[0] = FMA(TJ, TK, TL * TM);
		    rio[WS(ios, 4)] = FNMS(TL, TK, TJ * TM);
	       }
	  }
	  {
	       E To, TA, Tw, Ty, Tk, Tv;
	       Tk = Ti - Tj;
	       To = Tk - Tn;
	       TA = Tk + Tn;
	       Tv = Tt - Tu;
	       Tw = Ts + Tv;
	       Ty = Tv - Ts;
	       {
		    E Th, Tp, Tx, Tz;
		    Th = W[2];
		    Tp = W[3];
		    rio[WS(ios, 2)] = FNMS(Tp, Tw, Th * To);
		    iio[-WS(ios, 2)] = FMA(Th, Tw, Tp * To);
		    Tx = W[4];
		    Tz = W[5];
		    iio[-WS(ios, 1)] = FMA(Tx, Ty, Tz * TA);
		    rio[WS(ios, 3)] = FNMS(Tz, Ty, Tx * TA);
	       }
	  }
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 5},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 5, "hb_5", twinstr, &GENUS, {26, 14, 14, 0}, 0, 0, 0 };

void X(codelet_hb_5) (planner *p) {
     X(khc2hc_register) (p, hb_5, &desc);
}
#endif				/* HAVE_FMA */
