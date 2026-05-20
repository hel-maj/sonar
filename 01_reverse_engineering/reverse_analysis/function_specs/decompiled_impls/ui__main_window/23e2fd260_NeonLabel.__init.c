/* ===== 23e2fd260 ui.main_window:? ===== */
/* ghidra_name=FUN_23e2fd260 entry=23e2fd260 size=1869 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2fd260(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  code *pcVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  longlong lVar16;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar10 = _DAT_23eeaff18;
  plVar2 = (longlong *)*param_3;
  if (_DAT_23eeaff18 == (longlong *)0x0) {
LAB_23e2fd29a:
    _DAT_23eeaff18 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeac670,DAT_23eeac668,0x10);
  }
  else {
    lVar7 = *_DAT_23eeaff18;
    if (1 < lVar7) {
      *_DAT_23eeaff18 = lVar7 + -1;
      goto LAB_23e2fd29a;
    }
    if (_DAT_23eeaff18[2] != 0) {
      *_DAT_23eeaff18 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2fd29a;
    }
  }
  plVar3 = _DAT_23eeaff18;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeaff18 + 9;
  lVar9 = *(longlong *)(lVar7 + 8);
  _DAT_23eeaff18[0xf] = lVar9;
  *(longlong **)(lVar7 + 8) = plVar10;
  if ((lVar9 != 0) &&
     (((*(char *)(lVar9 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar9 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar9 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar9 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar9 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar7 = FUN_23e8f5700();
  if (lVar7 == 0) {
    plVar12 = (longlong *)0x0;
    FUN_23e915740(param_1,&uStack_68,DAT_23eeac718);
    uVar13 = 0x4a;
    uVar14 = uStack_68;
    uVar15 = uStack_60;
    plVar10 = plStack_58;
    goto LAB_23e2fd613;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeac6e0);
  if (plVar8 == (longlong *)0x0) {
LAB_23e2fd5f0:
    plVar10 = *(longlong **)(param_1 + 0x70);
    uVar14 = *(undefined8 *)(param_1 + 0x60);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = 0x4a;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar15 = *(undefined8 *)(param_1 + 0x68);
  }
  else {
    lVar9 = *(longlong *)(DAT_23eeac660 + 0x20);
    if (*(char *)(lVar9 + 10) == '\0') {
      plVar10 = (longlong *)FUN_23a37a020(DAT_23eeac660,_DAT_23eeac830);
      if (plVar10 == (longlong *)0x0) goto LAB_23e2fd551;
      lVar16 = *plVar10;
LAB_23e2fd910:
      if (lVar16 == 0) goto LAB_23e2fd551;
    }
    else {
      iVar6 = *(int *)(lVar9 + 0xc);
      if (*(int *)(lVar9 + 0xc) == 0) {
        *(int *)(lVar9 + 0xc) = DAT_23ec14e10;
        iVar6 = DAT_23ec14e10;
        DAT_23ec14e10 = DAT_23ec14e10 + 1;
      }
      if (_DAT_23ec14de0 != iVar6) {
        _DAT_23ec14de0 = iVar6;
        _DAT_23eeaff10 = FUN_23e8cbd60(lVar9,_DAT_23eeac830,*(undefined8 *)(_DAT_23eeac830 + 0x18));
      }
      if (-1 < _DAT_23eeaff10) {
        lVar1 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
        lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeaff10 * 0x10);
        if (lVar16 != 0) goto LAB_23e2fd3b6;
        _DAT_23eeaff10 = FUN_23e8cbd60(lVar9,_DAT_23eeac830,*(undefined8 *)(_DAT_23eeac830 + 0x18));
        if (-1 < _DAT_23eeaff10) {
          lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeaff10 * 0x10);
          goto LAB_23e2fd910;
        }
      }
LAB_23e2fd551:
      plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeac830);
      if ((plVar10 == (longlong *)0x0) || (lVar16 = *plVar10, lVar16 == 0)) {
        FUN_23e915740(param_1,&uStack_68,_DAT_23eeac830);
        *plVar8 = *plVar8 + -1;
        uVar14 = uStack_68;
        uVar15 = uStack_60;
        plVar10 = plStack_58;
        if (*plVar8 == 0) {
          plVar12 = (longlong *)0x0;
          (**(code **)(plVar8[1] + 0x30))(plVar8);
          uVar13 = 0x4a;
        }
        else {
          uVar13 = 0x4a;
          plVar12 = (longlong *)0x0;
        }
        goto LAB_23e2fd613;
      }
    }
LAB_23e2fd3b6:
    lVar9 = FUN_23e8f5700();
    if (lVar9 == 0) {
      FUN_23e915740(param_1,&uStack_68,DAT_23eeac718);
      uVar14 = uStack_68;
      uVar15 = uStack_60;
      plVar10 = plStack_58;
    }
    else {
      plVar10 = (longlong *)FUN_23e8c6640(lVar16,lVar9);
      if (plVar10 != (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e8c4990(plVar8,plVar10);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar11 != (longlong *)0x0) {
          plVar12 = (longlong *)FUN_23e8c09e0(lVar7,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (plVar12 == (longlong *)0x0) {
            uVar14 = *(undefined8 *)(param_1 + 0x60);
            uVar13 = 0x4a;
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar15 = *(undefined8 *)(param_1 + 0x68);
          }
          else {
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eeac6f0);
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0x4b;
              plVar8 = (longlong *)FUN_23e915840(param_1,plVar10,DAT_23eeac710,plVar12);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar8 != (longlong *)0x0) {
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar10 = *(longlong **)(lVar7 + 0x28);
                plVar3 = (longlong *)plVar10[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
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
                pcVar5 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                *plVar2 = *plVar2 + -1;
                if (*plVar2 != 0) {
                  return pcVar5;
                }
                (**(code **)(plVar2[1] + 0x30))(plVar2);
                return pcVar5;
              }
            }
            uVar14 = *(undefined8 *)(param_1 + 0x60);
            uVar13 = 0x4b;
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar15 = *(undefined8 *)(param_1 + 0x68);
          }
          goto LAB_23e2fd613;
        }
        goto LAB_23e2fd5f0;
      }
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar14 = *(undefined8 *)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar15 = *(undefined8 *)(param_1 + 0x68);
    }
    plVar12 = (longlong *)0x0;
    *plVar8 = *plVar8 + -1;
    uVar13 = 0x4a;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      uVar13 = 0x4a;
    }
  }
LAB_23e2fd613:
  plVar8 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar5 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar7 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar9 = plVar8[-1];
    puVar4 = *(undefined8 **)(lVar7 + 8);
    *puVar4 = plVar8 + -2;
    plVar8[-2] = lVar7;
    plVar8[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar7 + 8) = plVar8 + -2;
    plVar11 = plVar8;
  }
  else {
    plVar11 = plVar10;
    if ((longlong *)plVar10[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar5 = _PyRuntime_exref;
      plVar8[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar7 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar13;
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar9 = plVar8[-1];
      puVar4 = *(undefined8 **)(lVar7 + 8);
      *puVar4 = plVar8 + -2;
      plVar8[-2] = lVar7;
      plVar8[-1] = (ulonglong)((uint)lVar9 & 3) | (ulonglong)puVar4;
      lVar9 = *plVar10;
      *(longlong **)(lVar7 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar10;
      plVar11 = plVar8;
      if (lVar9 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5b14b,plVar2,plVar12);
  if (_DAT_23eeaff18 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeaff18 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar7 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
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
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uVar14,uVar15,plVar11);
  return (code *)0x0;
}
