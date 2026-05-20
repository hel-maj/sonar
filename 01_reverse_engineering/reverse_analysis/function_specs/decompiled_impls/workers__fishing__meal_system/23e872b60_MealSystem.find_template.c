/* ===== 23e872b60 workers.fishing.meal_system:299 ===== */
/* ghidra_name=FUN_23e872b60 entry=23e872b60 size=1487 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e872b60(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  code *pcVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  undefined4 uVar14;
  longlong *local_68;
  longlong *plStack_60;
  longlong *local_58;
  
  plVar10 = _DAT_23eedec68;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  if (_DAT_23eedec68 == (longlong *)0x0) {
LAB_23e872ba4:
    _DAT_23eedec68 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedec60,DAT_23eed7940,0x18);
  }
  else {
    lVar13 = *_DAT_23eedec68;
    if (1 < lVar13) {
      *_DAT_23eedec68 = lVar13 + -1;
      goto LAB_23e872ba4;
    }
    if (_DAT_23eedec68[2] != 0) {
      *_DAT_23eedec68 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e872ba4;
    }
  }
  plVar5 = _DAT_23eedec68;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedec68 + 9;
  lVar4 = *(longlong *)(lVar13 + 8);
  _DAT_23eedec68[0xf] = lVar4;
  *(longlong **)(lVar13 + 8) = plVar10;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed7458);
  if (plVar10 == (longlong *)0x0) {
LAB_23e872fb8:
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar14 = 0x130;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = DAT_23ed6a4f8;
  }
  else {
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed72d0);
    if (plVar11 != (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a38cc10(param_1,plVar11,plVar3);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar12 != (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,uRam000000023eed72b8);
        if (plVar11 == (longlong *)0x0) {
          uVar6 = *(undefined8 *)(param_1 + 0x60);
          uVar7 = *(undefined8 *)(param_1 + 0x68);
          plVar11 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          lVar13 = *plVar12;
          *plVar12 = lVar13 + -1;
          if (lVar13 + -1 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          uVar14 = 0x131;
          plVar12 = DAT_23ed6a4f8;
          goto joined_r0x00023e872fe1;
        }
        *(undefined4 *)(plVar5 + 5) = 0x130;
        local_68 = plVar2;
        plStack_60 = plVar12;
        local_58 = plVar11;
        lVar13 = FUN_23e956150(param_1,plVar10,&local_68);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        lVar4 = *plVar12;
        *plVar12 = lVar4 + -1;
        if (lVar4 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (lVar13 != 0) {
          lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar10 = *(longlong **)(lVar4 + 0x28);
          plVar5 = (longlong *)plVar10[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar4 + 0x30);
          *(undefined4 *)(plVar10 + 8) = 0xffffffff;
          if (plVar5 != (longlong *)0x0) {
            plVar10[2] = 0;
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))();
            }
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          plVar10[0xf] = 0;
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 != 0) {
            return lVar13;
          }
          (**(code **)(plVar3[1] + 0x30))(plVar3);
          return lVar13;
        }
        goto LAB_23e872fb8;
      }
    }
    uVar6 = *(undefined8 *)(param_1 + 0x60);
    uVar7 = *(undefined8 *)(param_1 + 0x68);
    uVar14 = 0x131;
    plVar11 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar10 = *plVar10 + -1;
    plVar12 = DAT_23ed6a4f8;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      uVar14 = 0x131;
      plVar12 = DAT_23ed6a4f8;
    }
  }
joined_r0x00023e872fe1:
  DAT_23ed6a4f8 = plVar12;
  if (plVar11 == (longlong *)0x0) {
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar12;
      *plVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar13 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar14;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar4 = plVar12[-1];
    puVar8 = *(undefined8 **)(lVar13 + 8);
    *puVar8 = plVar12 + -2;
    plVar12[-2] = lVar13;
    plVar12[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar8;
    *(longlong **)(lVar13 + 8) = plVar12 + -2;
    plVar10 = plVar12;
  }
  else {
    plVar10 = plVar11;
    if ((longlong *)plVar11[3] != plVar5) {
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar12;
        *plVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar9 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar5;
      *plVar5 = *plVar5 + 1;
      lVar13 = *(longlong *)(pcVar9 + 0x1f8);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar14;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
      lVar4 = plVar12[-1];
      puVar8 = *(undefined8 **)(lVar13 + 8);
      *puVar8 = plVar12 + -2;
      plVar12[-2] = lVar13;
      plVar12[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar8;
      lVar4 = *plVar11;
      *(longlong **)(lVar13 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar11;
      plVar10 = plVar12;
      if (lVar4 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
    }
  }
  FUN_23e8bba40(plVar5,&DAT_23ec5e2be,plVar1,plVar2,plVar3);
  if (_DAT_23eedec68 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eedec68 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar13 + 0x28);
  plVar11 = (longlong *)plVar5[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,uVar6,uVar7,plVar10);
  return 0;
}
