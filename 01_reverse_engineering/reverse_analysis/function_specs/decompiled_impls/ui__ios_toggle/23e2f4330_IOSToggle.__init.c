/* ===== 23e2f4330 ui.ios_toggle:56 ===== */
/* ghidra_name=FUN_23e2f4330 entry=23e2f4330 size=950 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e2f4330(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  
  plVar3 = _DAT_23eeb0048;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb0048 != (longlong *)0x0) {
    lVar10 = *_DAT_23eeb0048;
    if (lVar10 < 2) {
      if (_DAT_23eeb0048[2] == 0) goto LAB_23e2f4390;
      *_DAT_23eeb0048 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
    }
    else {
      *_DAT_23eeb0048 = lVar10 + -1;
    }
  }
  _DAT_23eeb0048 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0040,DAT_23eeb0078,8);
LAB_23e2f4390:
  plVar4 = _DAT_23eeb0048;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar3 = _DAT_23eeb0048 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eeb0048[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar3;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar3 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar3;
    if (plVar3 != (longlong *)0x0) {
      *plVar3 = *plVar3 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar5 = DAT_23eeacdc0;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar10 = FUN_23e8bc2f0(plVar1,uVar5);
  if (lVar10 == 0) {
    plVar3 = *(longlong **)(param_1 + 0x70);
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = DAT_23ed6a4f8;
    if (plVar3 == (longlong *)0x0) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar3 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar3;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar9;
      }
      plVar11[3] = (longlong)plVar4;
      plVar11[2] = 0;
      *plVar4 = *plVar4 + 1;
      plVar11[4] = 0x39ffffffff;
      lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar7 = plVar11[-1];
      puVar8 = *(undefined8 **)(lVar2 + 8);
      *puVar8 = plVar11 + -2;
      plVar11[-2] = lVar2;
      plVar11[-1] = (ulonglong)((uint)lVar7 & 3) | (ulonglong)puVar8;
      *(longlong **)(lVar2 + 8) = plVar11 + -2;
    }
    else {
      plVar11 = plVar3;
      if ((longlong *)plVar3[3] != plVar4) {
        if (DAT_23ed6a4f8 == (longlong *)0x0) {
          plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          plVar11 = (longlong *)*DAT_23ed6a4f8;
          *DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = plVar11;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          plVar11 = plVar9;
        }
        plVar11[3] = (longlong)plVar4;
        *plVar4 = *plVar4 + 1;
        plVar11[4] = 0x39ffffffff;
        lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8)
        ;
        lVar7 = plVar11[-1];
        puVar8 = *(undefined8 **)(lVar2 + 8);
        *puVar8 = plVar11 + -2;
        plVar11[-2] = lVar2;
        plVar11[-1] = (ulonglong)((uint)lVar7 & 3) | (ulonglong)puVar8;
        lVar7 = *plVar3;
        *(longlong **)(lVar2 + 8) = plVar11 + -2;
        plVar11[2] = (longlong)plVar3;
        if (lVar7 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
      }
    }
    FUN_23e8bba40(plVar4,&DAT_23ec5b149,plVar1);
    if (_DAT_23eeb0048 == plVar4) {
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
      }
      _DAT_23eeb0048 = (longlong *)0x0;
    }
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar3 = *(longlong **)(lVar2 + 0x28);
    plVar4 = (longlong *)plVar3[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
    *(undefined4 *)(plVar3 + 8) = 0xffffffff;
    if (plVar4 != (longlong *)0x0) {
      plVar3[2] = 0;
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))();
      }
    }
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    plVar3[0xf] = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    FUN_23a33aa70(param_1,uVar5,uVar6,plVar11);
  }
  else {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar3 = *(longlong **)(lVar2 + 0x28);
    plVar4 = (longlong *)plVar3[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
    *(undefined4 *)(plVar3 + 8) = 0xffffffff;
    if (plVar4 != (longlong *)0x0) {
      plVar3[2] = 0;
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))();
      }
    }
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    plVar3[0xf] = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
  }
  return lVar10;
}
