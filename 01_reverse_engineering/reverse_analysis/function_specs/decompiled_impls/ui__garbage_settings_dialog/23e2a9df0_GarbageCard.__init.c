/* ===== 23e2a9df0 ui.garbage_settings_dialog:? ===== */
/* ghidra_name=FUN_23e2a9df0 entry=23e2a9df0 size=1006 */

longlong FUN_23e2a9df0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  
  plVar7 = DAT_23eeb0410;
  plVar1 = (longlong *)*param_3;
  if (DAT_23eeb0410 != (longlong *)0x0) {
    lVar8 = *DAT_23eeb0410;
    if (lVar8 < 2) {
      if (DAT_23eeb0410[2] == 0) goto LAB_23e2a9e4e;
      *DAT_23eeb0410 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
    else {
      *DAT_23eeb0410 = lVar8 + -1;
    }
  }
  DAT_23eeb0410 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0468,DAT_23eeb0428,8);
LAB_23e2a9e4e:
  plVar3 = DAT_23eeb0410;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23eeb0410 + 9;
  lVar2 = *(longlong *)(lVar8 + 8);
  DAT_23eeb0410[0xf] = lVar2;
  *(longlong **)(lVar8 + 8) = plVar7;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar4 = DAT_23eeae3e0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar4);
  if (plVar7 != (longlong *)0x0) {
    *(undefined4 *)(plVar3 + 5) = 0x50;
    lVar8 = FUN_23e91bfe0(param_1,plVar7,DAT_23eeae408);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (lVar8 != 0) {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar7 = *(longlong **)(lVar2 + 0x28);
      plVar3 = (longlong *)plVar7[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
      *(undefined4 *)(plVar7 + 8) = 0xffffffff;
      if (plVar3 != (longlong *)0x0) {
        plVar7[2] = 0;
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))();
        }
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      plVar7[0xf] = 0;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return lVar8;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return lVar8;
    }
  }
  plVar7 = *(longlong **)(param_1 + 0x70);
  uVar4 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar5 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar9 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    plVar9[4] = 0x50ffffffff;
    lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar2 = plVar9[-1];
    puVar6 = *(undefined8 **)(lVar8 + 8);
    *puVar6 = plVar9 + -2;
    plVar9[-2] = lVar8;
    plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar8 + 8) = plVar9 + -2;
    plVar10 = plVar9;
  }
  else {
    plVar10 = plVar7;
    if ((longlong *)plVar7[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar9[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      plVar9[4] = 0x50ffffffff;
      lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar9[-1];
      puVar6 = *(undefined8 **)(lVar8 + 8);
      *puVar6 = plVar9 + -2;
      plVar9[-2] = lVar8;
      plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar6;
      lVar2 = *plVar7;
      *(longlong **)(lVar8 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar7;
      plVar10 = plVar9;
      if (lVar2 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5b149,plVar1);
  if (DAT_23eeb0410 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eeb0410 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar8 + 0x28);
  plVar3 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar4,uVar5,plVar10);
  return 0;
}
