/* ===== 23e133a90 telegram.notification_manager:166 ===== */
/* ghidra_name=FUN_23e133a90 entry=23e133a90 size=2282 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e133a90(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  code *pcVar14;
  undefined8 uVar15;
  longlong *plVar16;
  undefined8 uStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar8 = _DAT_23eeaad48;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeaad48 == (longlong *)0x0) {
LAB_23e133ace:
    _DAT_23eeaad48 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaad40,DAT_23eeaae08,0x20);
  }
  else {
    lVar9 = *_DAT_23eeaad48;
    if (1 < lVar9) {
      *_DAT_23eeaad48 = lVar9 + -1;
      goto LAB_23e133ace;
    }
    if (_DAT_23eeaad48[2] != 0) {
      *_DAT_23eeaad48 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e133ace;
    }
  }
  plVar4 = _DAT_23eeaad48;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeaad48 + 9;
  lVar3 = *(longlong *)(lVar9 + 8);
  _DAT_23eeaad48[0xf] = lVar3;
  *(longlong **)(lVar9 + 8) = plVar8;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  lVar9 = _DAT_23eea82f0;
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  uVar15 = DAT_23eea8230;
  *(undefined4 *)(plVar4 + 5) = 0xab;
  plVar8 = (longlong *)FUN_23e915840(param_1,plVar1,uVar15,*(undefined8 *)(lVar9 + 0x18));
  if (plVar8 == (longlong *)0x0) {
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = 0xab;
    uVar15 = *(undefined8 *)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e133fa1;
  }
  iVar7 = FUN_23a35f020(plVar8);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  pcVar14 = _Py_NoneStruct_exref;
  if (iVar7 == -1) {
    uVar15 = *(undefined8 *)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x68);
    plVar11 = (longlong *)0x0;
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar13 = 0xab;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e133fa1;
  }
  if (iVar7 == 0) {
    lVar9 = *(longlong *)(param_1 + 0x38);
    lVar3 = *(longlong *)(lVar9 + 8);
    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
    plVar8 = *(longlong **)(lVar3 + 0x28);
    plVar4 = (longlong *)plVar8[2];
    *(undefined8 *)(lVar9 + 8) = *(undefined8 *)(lVar3 + 0x30);
    *(undefined4 *)(plVar8 + 8) = 0xffffffff;
    if (plVar4 != (longlong *)0x0) {
      plVar8[2] = 0;
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))();
      }
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8[0xf] = 0;
    goto LAB_23e133bff;
  }
  iVar7 = FUN_23a35f020(plVar2);
  if (iVar7 == -1) {
    uVar15 = *(undefined8 *)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x68);
    plVar11 = (longlong *)0x0;
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar13 = 0xb0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    goto LAB_23e133fa1;
  }
  if (iVar7 == 0) {
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8268);
    lVar9 = _DAT_23eea8308;
    if (plVar12 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0xb4;
      plVar8 = (longlong *)FUN_23e915840(param_1,plVar1,DAT_23eea8220,*(undefined8 *)(lVar9 + 0x18))
      ;
      if (plVar8 == (longlong *)0x0) {
        uVar15 = *(undefined8 *)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x68);
        uVar13 = 0xb4;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = *plVar12 + -1;
        lVar9 = *plVar12;
        plVar11 = (longlong *)0x0;
joined_r0x00023e134345:
        if (lVar9 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        goto LAB_23e133fa1;
      }
      *(undefined4 *)(plVar4 + 5) = 0xb4;
      plVar10 = (longlong *)FUN_23e914090(param_1,plVar12,plVar8);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar11 = (longlong *)0x0;
LAB_23e133f00:
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar9 + 0x28);
        plVar4 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar8 + 8) = 0xffffffff;
        if (plVar4 != (longlong *)0x0) {
          plVar8[2] = 0;
          *plVar4 = *plVar4 + -1;
          if (*plVar4 == 0) {
            (**(code **)(plVar4[1] + 0x30))();
          }
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar8[0xf] = 0;
        pcVar14 = _Py_NoneStruct_exref;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
LAB_23e133bff:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return pcVar14;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar14;
      }
    }
    uVar15 = *(undefined8 *)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x68);
    plVar11 = (longlong *)0x0;
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar13 = 0xb4;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  else {
    lVar9 = FUN_23e8ff7a0();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,&uStack_68,DAT_23eea8258);
      uVar13 = 0xb1;
      plVar11 = (longlong *)0x0;
      uVar15 = uStack_68;
      plVar8 = plStack_60;
      plVar10 = plStack_58;
      goto LAB_23e133fa1;
    }
    lVar3 = *(longlong *)(param_1 + 0x10);
    plVar8 = *(longlong **)(lVar3 + 0xe18);
    if (plVar8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
    }
    else {
      lVar5 = plVar8[3];
      *(int *)(lVar3 + 0xeb8) = *(int *)(lVar3 + 0xeb8) + -1;
      *(longlong *)(lVar3 + 0xe18) = lVar5;
      *plVar8 = 1;
    }
    lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
    lVar5 = plVar8[-1];
    puVar6 = *(undefined8 **)(lVar3 + 8);
    *puVar6 = plVar8 + -2;
    plVar8[-2] = lVar3;
    plVar8[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar3 + 8) = plVar8 + -2;
    uVar15 = _DAT_23eea82f8;
    *plVar2 = *plVar2 + 1;
    plVar8[3] = (longlong)plVar2;
    plVar10 = (longlong *)FUN_23e8d7870(param_1,uVar15);
    *(undefined4 *)(plVar4 + 5) = 0xb1;
    plVar11 = (longlong *)FUN_23a334c60(param_1,lVar9,plVar8,plVar10);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) {
      uVar15 = *(undefined8 *)(param_1 + 0x60);
      uVar13 = 0xb1;
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar8 = *(longlong **)(param_1 + 0x68);
      goto LAB_23e133fa1;
    }
    plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8268);
    uVar15 = _DAT_23eea8300;
    if (plVar12 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0xb2;
      uStack_68 = uVar15;
      plStack_60 = plVar11;
      plVar8 = (longlong *)FUN_23e954670(param_1,plVar1,DAT_23eea8220,&uStack_68);
      if (plVar8 == (longlong *)0x0) {
        uVar15 = *(undefined8 *)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x68);
        uVar13 = 0xb2;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = *plVar12 + -1;
        lVar9 = *plVar12;
        goto joined_r0x00023e134345;
      }
      *(undefined4 *)(plVar4 + 5) = 0xb2;
      plVar10 = (longlong *)FUN_23e914090(param_1,plVar12,plVar8);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        goto LAB_23e133f00;
      }
    }
    uVar15 = *(undefined8 *)(param_1 + 0x60);
    uVar13 = 0xb2;
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar8 = *(longlong **)(param_1 + 0x68);
  }
LAB_23e133fa1:
  plVar12 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar14 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar9 = *(longlong *)(pcVar14 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar3 = plVar12[-1];
    puVar6 = *(undefined8 **)(lVar9 + 8);
    *puVar6 = plVar12 + -2;
    plVar12[-2] = lVar9;
    plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar9 + 8) = plVar12 + -2;
    plVar16 = plVar12;
  }
  else {
    plVar16 = plVar10;
    if ((longlong *)plVar10[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar16 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar16;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar12[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar13;
      pcVar14 = _PyRuntime_exref;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar12[-1];
      puVar6 = *(undefined8 **)(lVar9 + 8);
      *puVar6 = plVar12 + -2;
      plVar12[-2] = lVar9;
      plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
      lVar3 = *plVar10;
      *(longlong **)(lVar9 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar10;
      plVar16 = plVar12;
      if (lVar3 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5a43b,plVar1,plVar2,0,plVar11);
  if (_DAT_23eeaad48 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeaad48 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar9 + 0x28);
  plVar10 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar15,plVar8,plVar16);
  return (code *)0x0;
}
