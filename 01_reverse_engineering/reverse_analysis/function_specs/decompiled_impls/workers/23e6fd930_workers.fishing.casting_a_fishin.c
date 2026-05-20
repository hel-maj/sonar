/* ===== 23e6fd930 workers.fishing.casting_a_fishin:232 ===== */
/* ghidra_name=FUN_23e6fd930 entry=23e6fd930 size=1705 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e6fd930(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  undefined8 uVar12;
  undefined8 uStack_88;
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar6 = _DAT_23eedb1c0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eedb1c0 == (longlong *)0x0) {
LAB_23e6fd970:
    _DAT_23eedb1c0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb1b8,DAT_23eedb268,0x10);
  }
  else {
    lVar11 = *_DAT_23eedb1c0;
    if (1 < lVar11) {
      *_DAT_23eedb1c0 = lVar11 + -1;
      goto LAB_23e6fd970;
    }
    if (_DAT_23eedb1c0[2] != 0) {
      *_DAT_23eedb1c0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e6fd970;
    }
  }
  plVar4 = _DAT_23eedb1c0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eedb1c0 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  _DAT_23eedb1c0[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar6;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar12 = DAT_23eeda590;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,uVar12);
  if (plVar6 != (longlong *)0x0) {
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda4a8);
    if (plVar7 == (longlong *)0x0) {
      uStack_88 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e6fdc21;
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda4b0);
    if (plVar8 == (longlong *)0x0) {
      uStack_88 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e6fdc21;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda4b8);
    if (plVar9 == (longlong *)0x0) {
      uStack_88 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      lVar11 = *plVar8;
      *plVar8 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e6fdc21;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eeda4c0);
    if (plVar10 == (longlong *)0x0) {
      uStack_88 = *(undefined8 *)(param_1 + 0x60);
      uVar12 = *(undefined8 *)(param_1 + 0x68);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      lVar11 = *plVar8;
      *plVar8 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e6fdc21;
    }
    *(undefined4 *)(plVar4 + 5) = 0xe9;
    plStack_78 = plVar2;
    plStack_70 = plVar7;
    plStack_68 = plVar8;
    plStack_60 = plVar9;
    plStack_58 = plVar10;
    lVar11 = FUN_23e95b390(param_1,plVar6,&plStack_78);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    lVar3 = *plVar8;
    *plVar8 = lVar3 + -1;
    if (lVar3 + -1 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (lVar11 != 0) {
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar6 = *(longlong **)(lVar3 + 0x28);
      plVar4 = (longlong *)plVar6[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar3 + 0x30);
      *(undefined4 *)(plVar6 + 8) = 0xffffffff;
      if (plVar4 != (longlong *)0x0) {
        plVar6[2] = 0;
        *plVar4 = *plVar4 + -1;
        if (*plVar4 == 0) {
          (**(code **)(plVar4[1] + 0x30))();
        }
      }
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      plVar6[0xf] = 0;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 != 0) {
        return lVar11;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return lVar11;
    }
  }
  uStack_88 = *(undefined8 *)(param_1 + 0x60);
  plVar10 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar12 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e6fdc21:
  plVar6 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar6[2] = 0;
    plVar6[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    plVar6[4] = 0xe9ffffffff;
    lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar3 = plVar6[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar6 + -2;
    plVar6[-2] = lVar11;
    plVar6[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar6 + -2;
    plVar7 = plVar6;
  }
  else {
    plVar7 = plVar10;
    if ((longlong *)plVar10[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar6 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar7 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar7;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar6[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      plVar6[4] = 0xe9ffffffff;
      lVar11 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar6[-1];
      puVar5 = *(undefined8 **)(lVar11 + 8);
      *puVar5 = plVar6 + -2;
      plVar6[-2] = lVar11;
      plVar6[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar10;
      *(longlong **)(lVar11 + 8) = plVar6 + -2;
      plVar6[2] = (longlong)plVar10;
      plVar7 = plVar6;
      if (lVar3 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5dd15,plVar1,plVar2);
  if (_DAT_23eedb1c0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eedb1c0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar11 + 0x28);
  plVar4 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uStack_88,uVar12,plVar7);
  return 0;
}
