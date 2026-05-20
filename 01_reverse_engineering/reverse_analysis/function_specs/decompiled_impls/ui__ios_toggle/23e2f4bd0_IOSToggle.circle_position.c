/* ===== 23e2f4bd0 ui.ios_toggle:64 ===== */
/* ghidra_name=FUN_23e2f4bd0 entry=23e2f4bd0 size=1063 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e2f4bd0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  
  plVar9 = _DAT_23eeb0028;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeb0028 != (longlong *)0x0) {
    lVar10 = *_DAT_23eeb0028;
    if (lVar10 < 2) {
      if (_DAT_23eeb0028[2] == 0) goto LAB_23e2f4c34;
      *_DAT_23eeb0028 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
    else {
      *_DAT_23eeb0028 = lVar10 + -1;
    }
  }
  _DAT_23eeb0028 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb0020,DAT_23eeb0078,0x10);
LAB_23e2f4c34:
  plVar4 = _DAT_23eeb0028;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb0028 + 9;
  lVar3 = *(longlong *)(lVar10 + 8);
  _DAT_23eeb0028[0xf] = lVar3;
  *(longlong **)(lVar10 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar5 = _DAT_23eeace50;
  *(undefined4 *)(plVar4 + 8) = 0;
  *(undefined4 *)(plVar4 + 5) = 0x42;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar5);
  if (plVar9 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0x42;
    lVar10 = FUN_23e915840(param_1,plVar9,_DAT_23eeace58,plVar2);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (lVar10 != 0) {
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar9 = *(longlong **)(lVar3 + 0x28);
      plVar4 = (longlong *)plVar9[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
      *(undefined4 *)(plVar9 + 8) = 0xffffffff;
      if (plVar4 != (longlong *)0x0) {
        plVar9[2] = 0;
        *plVar4 = *plVar4 + -1;
        if (*plVar4 == 0) {
          (**(code **)(plVar4[1] + 0x30))();
        }
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      plVar9[0xf] = 0;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 != 0) {
        return lVar10;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return lVar10;
    }
  }
  plVar9 = *(longlong **)(param_1 + 0x70);
  uVar5 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar6 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar8 = DAT_23ed6a4f8;
  if (plVar9 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar8;
    }
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    plVar11[4] = 0x42ffffffff;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar11[-1];
    puVar7 = *(undefined8 **)(lVar10 + 8);
    *puVar7 = plVar11 + -2;
    plVar11[-2] = lVar10;
    plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar7;
    *(longlong **)(lVar10 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar9;
    if ((longlong *)plVar9[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar8;
      }
      plVar11[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      plVar11[4] = 0x42ffffffff;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar11[-1];
      puVar7 = *(undefined8 **)(lVar10 + 8);
      *puVar7 = plVar11 + -2;
      plVar11[-2] = lVar10;
      plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar7;
      lVar3 = *plVar9;
      *(longlong **)(lVar10 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar9;
      if (lVar3 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5b14b,plVar1,plVar2);
  if (_DAT_23eeb0028 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb0028 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar10 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar5,uVar6,plVar11);
  return 0;
}
