/* ===== 23c63ab20 license.license_client:432 ===== */
/* ghidra_name=FUN_23c63ab20 entry=23c63ab20 size=1086 */

longlong * FUN_23c63ab20(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  plVar7 = DAT_23ee29c30;
  plVar1 = (longlong *)*param_3;
  if (DAT_23ee29c30 == (longlong *)0x0) {
LAB_23c63ab58:
    DAT_23ee29c30 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29c28,DAT_23ee29d18,8);
  }
  else {
    lVar2 = *DAT_23ee29c30;
    if (1 < lVar2) {
      *DAT_23ee29c30 = lVar2 + -1;
      goto LAB_23c63ab58;
    }
    if (DAT_23ee29c30[2] != 0) {
      *DAT_23ee29c30 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23c63ab58;
    }
  }
  plVar4 = DAT_23ee29c30;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar7 = DAT_23ee29c30 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  DAT_23ee29c30[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar7;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar10 = DAT_23ee283b0;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar10);
  if (plVar7 != (longlong *)0x0) {
    iVar6 = FUN_23a35f020(plVar7);
    if (iVar6 == -1) {
      uVar10 = *(undefined8 *)(param_1 + 0x60);
      uVar11 = *(undefined8 *)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23c63ad0c;
    }
    if (iVar6 != 1) {
LAB_23c63ac10:
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar4 = *(longlong **)(lVar2 + 0x28);
      plVar8 = (longlong *)plVar4[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
      *(undefined4 *)(plVar4 + 8) = 0xffffffff;
      if (plVar8 != (longlong *)0x0) {
        plVar4[2] = 0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
        }
      }
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
      }
      plVar4[0xf] = 0;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return plVar7;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return plVar7;
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    *(undefined4 *)(plVar4 + 5) = 0x1b2;
    plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23ee28568);
    if (plVar7 != (longlong *)0x0) goto LAB_23c63ac10;
  }
  plVar8 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar10 = *(undefined8 *)(param_1 + 0x60);
  uVar11 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c63ad0c:
  plVar7 = DAT_23ed6a4f8;
  if (plVar8 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar7[3] = (longlong)plVar4;
    plVar7[2] = 0;
    *plVar4 = *plVar4 + 1;
    plVar7[4] = 0x1b2ffffffff;
    lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar7[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar7 + -2;
    plVar7[-2] = lVar2;
    plVar7[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar7 + -2;
    plVar9 = plVar7;
  }
  else {
    plVar9 = plVar8;
    if ((longlong *)plVar8[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar9 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar9;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar7[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      plVar7[4] = 0x1b2ffffffff;
      lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar7[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar7 + -2;
      plVar7[-2] = lVar2;
      plVar7[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar8;
      *(longlong **)(lVar2 + 8) = plVar7 + -2;
      plVar7[2] = (longlong)plVar8;
      plVar9 = plVar7;
      if (lVar3 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec47964,plVar1);
  if (DAT_23ee29c30 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23ee29c30 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
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
  FUN_23a33aa70(param_1,uVar10,uVar11,plVar9);
  return (longlong *)0x0;
}
