/* ===== 23e7e24b0 workers.fishing.memory_fish_read:58 ===== */
/* ghidra_name=FUN_23e7e24b0 entry=23e7e24b0 size=2018 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7e24b0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  code *pcVar6;
  int iVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  code *pcVar11;
  undefined4 uVar12;
  code *pcVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *local_68;
  code *local_60;
  longlong *local_58;
  
  plVar10 = _DAT_23eedebb0;
  plVar2 = (longlong *)*param_3;
  if (_DAT_23eedebb0 == (longlong *)0x0) {
LAB_23e7e24ea:
    _DAT_23eedebb0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeba8,DAT_23eedebc0,0x10);
  }
  else {
    lVar8 = *_DAT_23eedebb0;
    if (1 < lVar8) {
      *_DAT_23eedebb0 = lVar8 + -1;
      goto LAB_23e7e24ea;
    }
    if (_DAT_23eedebb0[2] != 0) {
      *_DAT_23eedebb0 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e7e24ea;
    }
  }
  plVar3 = _DAT_23eedebb0;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedebb0 + 9;
  lVar14 = *(longlong *)(lVar8 + 8);
  _DAT_23eedebb0[0xf] = lVar14;
  *(longlong **)(lVar8 + 8) = plVar10;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar8 = FUN_23e8dd910();
  if (lVar8 == 0) {
    FUN_23e915740(param_1,&local_68,_DAT_23eeddc10);
    uVar12 = 0x3b;
    pcVar11 = (code *)0x0;
    plVar5 = local_68;
    pcVar13 = local_60;
    plVar10 = local_58;
    plVar9 = DAT_23ed6a4f8;
    goto joined_r0x00023e7e2823;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23eeddc18);
  if (plVar9 == (longlong *)0x0) {
    plVar10 = *(longlong **)(param_1 + 0x70);
    plVar5 = *(longlong **)(param_1 + 0x60);
    pcVar11 = (code *)0x0;
    uVar12 = 0x3b;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar13 = *(code **)(param_1 + 0x68);
    plVar9 = DAT_23ed6a4f8;
    goto joined_r0x00023e7e2823;
  }
  lVar8 = *(longlong *)(DAT_23eeddba8 + 0x20);
  if (*(char *)(lVar8 + 10) == '\0') {
    plVar10 = (longlong *)FUN_23a37a020(DAT_23eeddba8,_DAT_23eeddc20);
    if (plVar10 == (longlong *)0x0) goto LAB_23e7e27b9;
    lVar14 = *plVar10;
LAB_23e7e2be8:
    if (lVar14 == 0) goto LAB_23e7e27b9;
LAB_23e7e2606:
    lVar8 = *(longlong *)(DAT_23eeddba8 + 0x20);
    if (*(char *)(lVar8 + 10) == '\0') {
      plVar10 = (longlong *)FUN_23a37a020(DAT_23eeddba8,_DAT_23eeddc28);
      if (plVar10 == (longlong *)0x0) goto LAB_23e7e29d9;
      lVar8 = *plVar10;
LAB_23e7e2c28:
      if (lVar8 == 0) goto LAB_23e7e29d9;
    }
    else {
      iVar7 = *(int *)(lVar8 + 0xc);
      if (*(int *)(lVar8 + 0xc) == 0) {
        *(int *)(lVar8 + 0xc) = DAT_23ec15618;
        iVar7 = DAT_23ec15618;
        DAT_23ec15618 = DAT_23ec15618 + 1;
      }
      if (_DAT_23ec1561c != iVar7) {
        _DAT_23ec1561c = iVar7;
        _DAT_23eedeba0 = FUN_23e8cbd60(lVar8,_DAT_23eeddc28,*(undefined8 *)(_DAT_23eeddc28 + 0x18));
      }
      if (-1 < _DAT_23eedeba0) {
        lVar1 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
        if (*(longlong *)(lVar1 + 8 + _DAT_23eedeba0 * 0x10) != 0) goto LAB_23e7e2673;
        _DAT_23eedeba0 = FUN_23e8cbd60(lVar8,_DAT_23eeddc28,*(undefined8 *)(_DAT_23eeddc28 + 0x18));
        if (-1 < _DAT_23eedeba0) {
          lVar8 = *(longlong *)(lVar1 + 8 + _DAT_23eedeba0 * 0x10);
          goto LAB_23e7e2c28;
        }
      }
LAB_23e7e29d9:
      plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeddc28);
      lVar8 = _DAT_23eeddc28;
      if ((plVar10 == (longlong *)0x0) || (*plVar10 == 0)) goto LAB_23e7e27ec;
    }
LAB_23e7e2673:
    plVar10 = (longlong *)FUN_23e8c1360(lVar14);
    if (plVar10 == (longlong *)0x0) {
      plVar5 = *(longlong **)(param_1 + 0x60);
      pcVar13 = *(code **)(param_1 + 0x68);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        pcVar11 = (code *)0x0;
        (**(code **)(plVar9[1] + 0x30))(plVar9);
        uVar12 = 0x3b;
        plVar9 = DAT_23ed6a4f8;
      }
      else {
        pcVar11 = (code *)0x0;
        uVar12 = 0x3b;
        plVar9 = DAT_23ed6a4f8;
      }
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x3b;
      local_60 = _Py_FalseStruct_exref;
      local_68 = plVar10;
      local_58 = plVar2;
      pcVar11 = (code *)FUN_23e956150(param_1,plVar9,&local_68);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (pcVar11 == (code *)0x0) {
        plVar5 = *(longlong **)(param_1 + 0x60);
        uVar12 = 0x3b;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar13 = *(code **)(param_1 + 0x68);
        plVar9 = DAT_23ed6a4f8;
      }
      else {
        iVar7 = FUN_23a35f020(pcVar11);
        if (iVar7 != -1) {
          lVar8 = *(longlong *)(param_1 + 0x38);
          pcVar13 = pcVar11;
          if (iVar7 == 0) {
            pcVar13 = _Py_NoneStruct_exref;
          }
          lVar14 = *(longlong *)(lVar8 + 8);
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + 1;
          plVar10 = *(longlong **)(lVar14 + 0x28);
          plVar3 = (longlong *)plVar10[2];
          *(undefined8 *)(lVar8 + 8) = *(undefined8 *)(lVar14 + 0x30);
          *(undefined4 *)(plVar10 + 8) = 0xffffffff;
          if (plVar3 != (longlong *)0x0) {
            plVar10[2] = 0;
            *plVar3 = *plVar3 + -1;
            if (*plVar3 == 0) {
              (**(code **)(plVar3[1] + 0x30))();
            }
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          plVar10[0xf] = 0;
          *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
          if (*(longlong *)pcVar11 == 0) {
            (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
          }
          *plVar2 = *plVar2 + -1;
          if (*plVar2 != 0) {
            return pcVar13;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return pcVar13;
        }
        plVar5 = *(longlong **)(param_1 + 0x60);
        uVar12 = 0x3c;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar13 = *(code **)(param_1 + 0x68);
        plVar9 = DAT_23ed6a4f8;
      }
    }
  }
  else {
    iVar7 = *(int *)(lVar8 + 0xc);
    if (*(int *)(lVar8 + 0xc) == 0) {
      *(int *)(lVar8 + 0xc) = DAT_23ec15618;
      iVar7 = DAT_23ec15618;
      DAT_23ec15618 = DAT_23ec15618 + 1;
    }
    if (_DAT_23ec15614 != iVar7) {
      _DAT_23ec15614 = iVar7;
      _DAT_23eedeb98 = FUN_23e8cbd60(lVar8,_DAT_23eeddc20,*(undefined8 *)(_DAT_23eeddc20 + 0x18));
    }
    if (-1 < _DAT_23eedeb98) {
      lVar1 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
      lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eedeb98 * 0x10);
      if (lVar14 != 0) goto LAB_23e7e2606;
      _DAT_23eedeb98 = FUN_23e8cbd60(lVar8,_DAT_23eeddc20,*(undefined8 *)(_DAT_23eeddc20 + 0x18));
      if (-1 < _DAT_23eedeb98) {
        lVar14 = *(longlong *)(lVar1 + 8 + _DAT_23eedeb98 * 0x10);
        goto LAB_23e7e2be8;
      }
    }
LAB_23e7e27b9:
    plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeddc20);
    lVar8 = _DAT_23eeddc20;
    if ((plVar10 != (longlong *)0x0) && (lVar14 = *plVar10, lVar14 != 0)) goto LAB_23e7e2606;
LAB_23e7e27ec:
    FUN_23e915740(param_1,&local_68,lVar8);
    plVar10 = local_58;
    pcVar13 = local_60;
    plVar5 = local_68;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      pcVar11 = (code *)0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar12 = 0x3b;
      plVar9 = DAT_23ed6a4f8;
    }
    else {
      uVar12 = 0x3b;
      pcVar11 = (code *)0x0;
      plVar9 = DAT_23ed6a4f8;
    }
  }
joined_r0x00023e7e2823:
  DAT_23ed6a4f8 = plVar9;
  if (plVar10 == (longlong *)0x0) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar8 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar12;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar14 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar8 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar8;
    plVar9[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar8 + 8) = plVar9 + -2;
    plVar15 = plVar9;
  }
  else {
    plVar15 = plVar10;
    if ((longlong *)plVar10[3] != plVar3) {
      if (plVar9 == (longlong *)0x0) {
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar9;
        *plVar9 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar6 = _PyRuntime_exref;
      plVar9[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar8 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar12;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
      lVar14 = plVar9[-1];
      puVar4 = *(undefined8 **)(lVar8 + 8);
      *puVar4 = plVar9 + -2;
      plVar9[-2] = lVar8;
      plVar9[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar4;
      lVar14 = *plVar10;
      *(longlong **)(lVar8 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar10;
      plVar15 = plVar9;
      if (lVar14 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5e407,plVar2,pcVar11);
  if (_DAT_23eedebb0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedebb0 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar8 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  if ((pcVar11 != (code *)0x0) &&
     (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar5,pcVar13,plVar15);
  return (code *)0x0;
}
