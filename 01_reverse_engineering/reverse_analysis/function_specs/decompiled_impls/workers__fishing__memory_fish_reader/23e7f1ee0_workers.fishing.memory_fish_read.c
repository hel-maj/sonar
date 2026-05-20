/* ===== 23e7f1ee0 workers.fishing.memory_fish_read:208 ===== */
/* ghidra_name=FUN_23e7f1ee0 entry=23e7f1ee0 size=1148 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e7f1ee0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  plVar7 = _DAT_23eedeab0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eedeab0 == (longlong *)0x0) {
LAB_23e7f1f1e:
    _DAT_23eedeab0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeaa8,DAT_23eedebc0,0x10);
  }
  else {
    lVar9 = *_DAT_23eedeab0;
    if (1 < lVar9) {
      *_DAT_23eedeab0 = lVar9 + -1;
      goto LAB_23e7f1f1e;
    }
    if (_DAT_23eedeab0[2] != 0) {
      *_DAT_23eedeab0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e7f1f1e;
    }
  }
  plVar4 = _DAT_23eedeab0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eedeab0 + 9;
  lVar3 = *(longlong *)(lVar9 + 8);
  _DAT_23eedeab0[0xf] = lVar3;
  *(longlong **)(lVar9 + 8) = plVar7;
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
  uVar12 = _DAT_23eedde78;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar12);
  if (plVar7 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0xd2;
    plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,_DAT_23eeddf00,plVar2);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      lVar9 = FUN_23e8bc2f0(plVar1,_DAT_23eedde90);
      if (lVar9 != 0) {
        lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar7 = *(longlong **)(lVar3 + 0x28);
        plVar4 = (longlong *)plVar7[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
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
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return lVar9;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return lVar9;
      }
      uVar12 = *(undefined8 *)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      uVar11 = 0xd3;
      plVar7 = *(longlong **)(param_1 + 0x70);
      goto LAB_23e7f2101;
    }
  }
  uVar12 = *(undefined8 *)(param_1 + 0x60);
  uVar13 = *(undefined8 *)(param_1 + 0x68);
  uVar11 = 0xd2;
  plVar7 = *(longlong **)(param_1 + 0x70);
LAB_23e7f2101:
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar8 = DAT_23ed6a4f8;
  if (plVar7 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = plVar8;
    }
    pcVar6 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar9 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar11;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar9 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar9;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar9 + 8) = plVar10 + -2;
  }
  else {
    plVar10 = plVar7;
    if ((longlong *)plVar7[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar10 = plVar8;
      }
      pcVar6 = _PyRuntime_exref;
      plVar10[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar9 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar11;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar3 = plVar10[-1];
      puVar5 = *(undefined8 **)(lVar9 + 8);
      *puVar5 = plVar10 + -2;
      plVar10[-2] = lVar9;
      plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar7;
      *(longlong **)(lVar9 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar7;
      if (lVar3 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5e407,plVar1,plVar2);
  if (_DAT_23eedeab0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eedeab0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar9 + 0x28);
  plVar4 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
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
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar12,uVar13,plVar10);
  return 0;
}
