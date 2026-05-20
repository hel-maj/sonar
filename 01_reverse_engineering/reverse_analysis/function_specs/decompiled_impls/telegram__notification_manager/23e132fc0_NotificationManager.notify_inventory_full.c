/* ===== 23e132fc0 telegram.notification_manager:146 ===== */
/* ghidra_name=FUN_23e132fc0 entry=23e132fc0 size=2656 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e132fc0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined4 uVar15;
  code *pcVar16;
  undefined8 *puVar17;
  undefined8 uVar18;
  undefined8 uStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_f8;
  longlong lStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  undefined8 *puStack_d0;
  longlong *plStack_c8;
  undefined8 *puStack_c0;
  longlong *local_98;
  longlong *local_90;
  longlong *local_80;
  undefined8 local_78;
  undefined8 local_70;
  longlong *local_68;
  undefined8 uStack_60;
  
  plVar6 = _DAT_23eeaad58;
  plVar11 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar13 = (longlong *)param_3[2];
  if (_DAT_23eeaad58 == (longlong *)0x0) {
LAB_23e133007:
    puStack_c0 = (undefined8 *)0x23e133023;
    _DAT_23eeaad58 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaad50,DAT_23eeaae08,0x20);
  }
  else {
    lVar7 = *_DAT_23eeaad58;
    if (1 < lVar7) {
      *_DAT_23eeaad58 = lVar7 + -1;
      goto LAB_23e133007;
    }
    if (_DAT_23eeaad58[2] != 0) {
      *_DAT_23eeaad58 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        puStack_c0 = (undefined8 *)0x23e133402;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e133007;
    }
  }
  plVar14 = _DAT_23eeaad58;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eeaad58 + 9;
  lVar12 = *(longlong *)(lVar7 + 8);
  _DAT_23eeaad58[0xf] = lVar12;
  *(longlong **)(lVar7 + 8) = plVar6;
  if ((lVar12 != 0) &&
     (((*(char *)(lVar12 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar12 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar12 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar12 + 0x38))) && (plVar14[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar12 + 0x28);
    *(longlong **)(plVar14[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  lVar7 = _DAT_23eea82c8;
  *plVar14 = *plVar14 + 1;
  *(undefined4 *)(plVar14 + 8) = 0;
  uVar18 = DAT_23eea8230;
  *(undefined4 *)(plVar14 + 5) = 0x98;
  puStack_c0 = (undefined8 *)0x23e1330ae;
  plVar6 = (longlong *)FUN_23e915840(param_1,plVar11,uVar18,*(undefined8 *)(lVar7 + 0x18));
  if (plVar6 == (longlong *)0x0) {
    local_78 = *(undefined8 *)(param_1 + 0x60);
    plVar6 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x98;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
    plVar9 = (longlong *)*(undefined8 *)(param_1 + 0x68);
    goto LAB_23e133573;
  }
  puStack_c0 = (undefined8 *)0x23e1330c2;
  iVar5 = FUN_23a35f020(plVar6);
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    puStack_c0 = (undefined8 *)0x23e133192;
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  pcVar16 = _Py_NoneStruct_exref;
  if (iVar5 == -1) {
    local_78 = *(undefined8 *)(param_1 + 0x60);
    plVar6 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x98;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)*(undefined8 *)(param_1 + 0x68);
    goto LAB_23e133573;
  }
  if (iVar5 == 0) {
    lVar7 = *(longlong *)(param_1 + 0x38);
    lVar12 = *(longlong *)(lVar7 + 8);
    *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
    plVar6 = *(longlong **)(lVar12 + 0x28);
    plVar14 = (longlong *)plVar6[2];
    *(undefined8 *)(lVar7 + 8) = *(undefined8 *)(lVar12 + 0x30);
    *(undefined4 *)(plVar6 + 8) = 0xffffffff;
    if (plVar14 != (longlong *)0x0) {
      plVar6[2] = 0;
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        puStack_c0 = (undefined8 *)0x23e133126;
        (**(code **)(plVar14[1] + 0x30))();
      }
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      puStack_c0 = (undefined8 *)0x23e13341a;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    plVar6[0xf] = 0;
    goto LAB_23e133138;
  }
  puStack_c0 = (undefined8 *)0x23e1331a8;
  iVar5 = FUN_23a35f020(plVar13);
  plVar6 = _DAT_23eea82d0;
  if (iVar5 == -1) {
    local_78 = *(undefined8 *)(param_1 + 0x60);
    plVar6 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar15 = 0x9b;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)*(undefined8 *)(param_1 + 0x68);
    goto LAB_23e133573;
  }
  lVar7 = *(longlong *)(param_1 + 0x10);
  plVar10 = *(longlong **)(lVar7 + 0xe28);
  local_68 = plVar2;
  if (iVar5 == 0) {
    if (plVar10 == (longlong *)0x0) {
      puStack_c0 = (undefined8 *)0x23e133861;
      plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
    }
    else {
      lVar12 = plVar10[3];
      *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
      *(longlong *)(lVar7 + 0xe28) = lVar12;
      *plVar10 = 1;
    }
    pcVar16 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar10 + 4) = (undefined1  [16])0x0;
    lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
    lVar12 = plVar10[-1];
    puVar17 = *(undefined8 **)(lVar7 + 8);
    *puVar17 = plVar10 + -2;
    plVar10[-2] = lVar7;
    plVar10[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar7 + 8) = plVar10 + -2;
    plVar9 = DAT_23ed6a4c0;
    *plVar6 = *plVar6 + 1;
    plVar10[3] = (longlong)plVar6;
    uVar18 = DAT_23ed6cd28;
    if (plVar9 == (longlong *)0x0) {
      puStack_c0 = (undefined8 *)0x23e1339b7;
      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar9 == (longlong *)0x0) {
LAB_23e133a70:
        puStack_c0 = (undefined8 *)0x23e133a78;
        PyErr_PrintEx(0,0);
        lVar7 = 1;
        puStack_c0 = (undefined8 *)0x23e133a83;
        Py_Exit();
        plVar8 = _DAT_23eeaad48;
        puStack_c0 = &DAT_23ed6a4c0;
        puStack_d0 = &DAT_23ed6cce0;
        plVar6 = (longlong *)*puVar17;
        plVar9 = (longlong *)puVar17[1];
        plStack_f8 = plVar14;
        lStack_f0 = param_1;
        plStack_e8 = plVar11;
        plStack_e0 = plVar13;
        plStack_d8 = plVar2;
        plStack_c8 = plVar10;
        if (_DAT_23eeaad48 == (longlong *)0x0) {
LAB_23e133ace:
          _DAT_23eeaad48 = (longlong *)FUN_23e91f3b0(lVar7,DAT_23eeaad40,DAT_23eeaae08,0x20);
        }
        else {
          lVar12 = *_DAT_23eeaad48;
          if (1 < lVar12) {
            *_DAT_23eeaad48 = lVar12 + -1;
            goto LAB_23e133ace;
          }
          if (_DAT_23eeaad48[2] != 0) {
            *_DAT_23eeaad48 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            goto LAB_23e133ace;
          }
        }
        plVar2 = _DAT_23eeaad48;
        lVar12 = *(longlong *)(lVar7 + 0x38);
        plVar11 = _DAT_23eeaad48 + 9;
        lVar3 = *(longlong *)(lVar12 + 8);
        _DAT_23eeaad48[0xf] = lVar3;
        *(longlong **)(lVar12 + 8) = plVar11;
        if (((lVar3 != 0) &&
            ((*(char *)(lVar3 + 0x45) == '\x01' ||
             ((ulonglong)
              (*(longlong *)(lVar3 + 0x20) + 0xb8 +
              (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <=
              *(ulonglong *)(lVar3 + 0x38))))) && (plVar2[0xe] != 0)) {
          plVar11 = *(longlong **)(lVar3 + 0x28);
          *(longlong **)(plVar2[0xe] + 0x10) = plVar11;
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + 1;
          }
        }
        lVar12 = _DAT_23eea82f0;
        *plVar2 = *plVar2 + 1;
        *(undefined4 *)(plVar2 + 8) = 0;
        uVar18 = DAT_23eea8230;
        *(undefined4 *)(plVar2 + 5) = 0xab;
        plVar11 = (longlong *)FUN_23e915840(lVar7,plVar6,uVar18,*(undefined8 *)(lVar12 + 0x18));
        if (plVar11 == (longlong *)0x0) {
          plVar13 = *(longlong **)(lVar7 + 0x70);
          *(undefined8 *)(lVar7 + 0x70) = 0;
          uVar15 = 0xab;
          uVar18 = *(undefined8 *)(lVar7 + 0x60);
          plVar11 = *(longlong **)(lVar7 + 0x68);
          *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
          plVar14 = (longlong *)0x0;
          goto LAB_23e133fa1;
        }
        iVar5 = FUN_23a35f020(plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        pcVar16 = _Py_NoneStruct_exref;
        if (iVar5 == -1) {
          uVar18 = *(undefined8 *)(lVar7 + 0x60);
          plVar11 = *(longlong **)(lVar7 + 0x68);
          plVar14 = (longlong *)0x0;
          plVar13 = *(longlong **)(lVar7 + 0x70);
          *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
          uVar15 = 0xab;
          *(undefined8 *)(lVar7 + 0x70) = 0;
          goto LAB_23e133fa1;
        }
        if (iVar5 == 0) {
          lVar7 = *(longlong *)(lVar7 + 0x38);
          lVar12 = *(longlong *)(lVar7 + 8);
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          plVar11 = *(longlong **)(lVar12 + 0x28);
          plVar2 = (longlong *)plVar11[2];
          *(undefined8 *)(lVar7 + 8) = *(undefined8 *)(lVar12 + 0x30);
          *(undefined4 *)(plVar11 + 8) = 0xffffffff;
          if (plVar2 != (longlong *)0x0) {
            plVar11[2] = 0;
            *plVar2 = *plVar2 + -1;
            if (*plVar2 == 0) {
              (**(code **)(plVar2[1] + 0x30))();
            }
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          plVar11[0xf] = 0;
          goto LAB_23e133bff;
        }
        iVar5 = FUN_23a35f020(plVar9);
        if (iVar5 == -1) {
          uVar18 = *(undefined8 *)(lVar7 + 0x60);
          plVar11 = *(longlong **)(lVar7 + 0x68);
          plVar14 = (longlong *)0x0;
          plVar13 = *(longlong **)(lVar7 + 0x70);
          *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
          uVar15 = 0xb0;
          *(undefined8 *)(lVar7 + 0x70) = 0;
          goto LAB_23e133fa1;
        }
        if (iVar5 == 0) {
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23eea8268);
          lVar12 = _DAT_23eea8308;
          if (plVar8 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0xb4;
            plVar11 = (longlong *)
                      FUN_23e915840(lVar7,plVar6,DAT_23eea8220,*(undefined8 *)(lVar12 + 0x18));
            if (plVar11 == (longlong *)0x0) {
              uVar18 = *(undefined8 *)(lVar7 + 0x60);
              plVar11 = *(longlong **)(lVar7 + 0x68);
              uVar15 = 0xb4;
              plVar13 = *(longlong **)(lVar7 + 0x70);
              *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(lVar7 + 0x70) = 0;
              *plVar8 = *plVar8 + -1;
              lVar12 = *plVar8;
              plVar14 = (longlong *)0x0;
joined_r0x00023e134345:
              if (lVar12 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              goto LAB_23e133fa1;
            }
            *(undefined4 *)(plVar2 + 5) = 0xb4;
            plVar13 = (longlong *)FUN_23e914090(lVar7,plVar8,plVar11);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar13 != (longlong *)0x0) {
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              plVar14 = (longlong *)0x0;
LAB_23e133f00:
              lVar12 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
              plVar11 = *(longlong **)(lVar12 + 0x28);
              plVar2 = (longlong *)plVar11[2];
              *(undefined8 *)(*(longlong *)(lVar7 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
              *(undefined4 *)(plVar11 + 8) = 0xffffffff;
              if (plVar2 != (longlong *)0x0) {
                plVar11[2] = 0;
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))();
                }
              }
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              plVar11[0xf] = 0;
              pcVar16 = _Py_NoneStruct_exref;
              *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
              if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
LAB_23e133bff:
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
                return pcVar16;
              }
              return pcVar16;
            }
          }
          uVar18 = *(undefined8 *)(lVar7 + 0x60);
          plVar11 = *(longlong **)(lVar7 + 0x68);
          plVar14 = (longlong *)0x0;
          plVar13 = *(longlong **)(lVar7 + 0x70);
          *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
          uVar15 = 0xb4;
          *(undefined8 *)(lVar7 + 0x70) = 0;
        }
        else {
          lVar12 = FUN_23e8ff7a0();
          if (lVar12 == 0) {
            FUN_23e915740(lVar7,&uStack_120,DAT_23eea8258);
            uVar15 = 0xb1;
            plVar14 = (longlong *)0x0;
            uVar18 = uStack_120;
            plVar11 = plStack_118;
            plVar13 = plStack_110;
            goto LAB_23e133fa1;
          }
          lVar3 = *(longlong *)(lVar7 + 0x10);
          plVar11 = *(longlong **)(lVar3 + 0xe18);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
          }
          else {
            lVar4 = plVar11[3];
            *(int *)(lVar3 + 0xeb8) = *(int *)(lVar3 + 0xeb8) + -1;
            *(longlong *)(lVar3 + 0xe18) = lVar4;
            *plVar11 = 1;
          }
          lVar3 = *(longlong *)
                   (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar4 = plVar11[-1];
          puVar17 = *(undefined8 **)(lVar3 + 8);
          *puVar17 = plVar11 + -2;
          plVar11[-2] = lVar3;
          plVar11[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar17;
          *(longlong **)(lVar3 + 8) = plVar11 + -2;
          uVar18 = _DAT_23eea82f8;
          *plVar9 = *plVar9 + 1;
          plVar11[3] = (longlong)plVar9;
          plVar13 = (longlong *)FUN_23e8d7870(lVar7,uVar18);
          *(undefined4 *)(plVar2 + 5) = 0xb1;
          plVar14 = (longlong *)FUN_23a334c60(lVar7,lVar12,plVar11,plVar13);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar14 == (longlong *)0x0) {
            uVar18 = *(undefined8 *)(lVar7 + 0x60);
            uVar15 = 0xb1;
            plVar13 = *(longlong **)(lVar7 + 0x70);
            *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(lVar7 + 0x70) = 0;
            plVar11 = *(longlong **)(lVar7 + 0x68);
            goto LAB_23e133fa1;
          }
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar6,DAT_23eea8268);
          uVar18 = _DAT_23eea8300;
          if (plVar8 != (longlong *)0x0) {
            *(undefined4 *)(plVar2 + 5) = 0xb2;
            uStack_120 = uVar18;
            plStack_118 = plVar14;
            plVar11 = (longlong *)FUN_23e954670(lVar7,plVar6,DAT_23eea8220,&uStack_120);
            if (plVar11 == (longlong *)0x0) {
              uVar18 = *(undefined8 *)(lVar7 + 0x60);
              plVar11 = *(longlong **)(lVar7 + 0x68);
              uVar15 = 0xb2;
              plVar13 = *(longlong **)(lVar7 + 0x70);
              *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(lVar7 + 0x70) = 0;
              *plVar8 = *plVar8 + -1;
              lVar12 = *plVar8;
              goto joined_r0x00023e134345;
            }
            *(undefined4 *)(plVar2 + 5) = 0xb2;
            plVar13 = (longlong *)FUN_23e914090(lVar7,plVar8,plVar11);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar13 != (longlong *)0x0) {
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              goto LAB_23e133f00;
            }
          }
          uVar18 = *(undefined8 *)(lVar7 + 0x60);
          uVar15 = 0xb2;
          plVar13 = *(longlong **)(lVar7 + 0x70);
          *(undefined1 (*) [16])(lVar7 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(lVar7 + 0x70) = 0;
          plVar11 = *(longlong **)(lVar7 + 0x68);
        }
LAB_23e133fa1:
        plVar8 = DAT_23ed6a4f8;
        if (plVar13 == (longlong *)0x0) {
          if (DAT_23ed6a4f8 == (longlong *)0x0) {
            plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            plVar13 = (longlong *)*DAT_23ed6a4f8;
            *DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = plVar13;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          pcVar16 = _PyRuntime_exref;
          plVar8[2] = 0;
          plVar8[3] = (longlong)plVar2;
          *plVar2 = *plVar2 + 1;
          lVar12 = *(longlong *)(pcVar16 + 0x1f8);
          *(undefined4 *)((longlong)plVar8 + 0x24) = uVar15;
          lVar12 = *(longlong *)(lVar12 + 0x10);
          *(undefined4 *)(plVar8 + 4) = 0xffffffff;
          lVar12 = *(longlong *)(lVar12 + 0x2e8);
          lVar3 = plVar8[-1];
          puVar17 = *(undefined8 **)(lVar12 + 8);
          *puVar17 = plVar8 + -2;
          plVar8[-2] = lVar12;
          plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar17;
          *(longlong **)(lVar12 + 8) = plVar8 + -2;
          plVar10 = plVar8;
        }
        else {
          plVar10 = plVar13;
          if ((longlong *)plVar13[3] != plVar2) {
            if (DAT_23ed6a4f8 == (longlong *)0x0) {
              plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              plVar10 = (longlong *)*DAT_23ed6a4f8;
              *DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = plVar10;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            plVar8[3] = (longlong)plVar2;
            *plVar2 = *plVar2 + 1;
            *(undefined4 *)((longlong)plVar8 + 0x24) = uVar15;
            pcVar16 = _PyRuntime_exref;
            *(undefined4 *)(plVar8 + 4) = 0xffffffff;
            lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
            lVar3 = plVar8[-1];
            puVar17 = *(undefined8 **)(lVar12 + 8);
            *puVar17 = plVar8 + -2;
            plVar8[-2] = lVar12;
            plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar17;
            lVar3 = *plVar13;
            *(longlong **)(lVar12 + 8) = plVar8 + -2;
            plVar8[2] = (longlong)plVar13;
            plVar10 = plVar8;
            if (lVar3 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
          }
        }
        FUN_23e8bba40(plVar2,&DAT_23ec5a43b,plVar6,plVar9,0,plVar14);
        if (_DAT_23eeaad48 == plVar2) {
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          _DAT_23eeaad48 = (longlong *)0x0;
        }
        lVar12 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
        plVar2 = *(longlong **)(lVar12 + 0x28);
        plVar13 = (longlong *)plVar2[2];
        *(undefined8 *)(*(longlong *)(lVar7 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
        *(undefined4 *)(plVar2 + 8) = 0xffffffff;
        if (plVar13 != (longlong *)0x0) {
          plVar2[2] = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 == 0) {
          (**(code **)(plVar2[1] + 0x30))(plVar2);
        }
        plVar2[0xf] = 0;
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        FUN_23a33aa70(lVar7,uVar18,plVar11,plVar10);
        return (code *)0x0;
      }
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a4c0 = plVar9;
    }
    uStack_60 = uVar18;
    puStack_c0 = (undefined8 *)0x23e13327a;
    lVar7 = FUN_23e94ed00(param_1,plVar9,&local_68);
    if (lVar7 == 0) {
      local_78 = *(undefined8 *)(param_1 + 0x60);
      plVar6 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = 0xa3;
      local_80 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      lVar7 = *plVar10;
joined_r0x00023e1338af:
      plVar8 = (longlong *)0x0;
      plVar9 = local_80;
      if (lVar7 == 0) {
        plVar8 = (longlong *)0x0;
        local_70._4_4_ = (undefined4)((ulonglong)local_70 >> 0x20);
        local_70 = (longlong *)CONCAT44(local_70._4_4_,uVar15);
        puStack_c0 = (undefined8 *)0x23e1338c3;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        plVar9 = local_80;
        uVar15 = (undefined4)local_70;
      }
      goto LAB_23e133573;
    }
    plVar10[4] = lVar7;
    plVar6 = _DAT_23eea82e0;
    *_DAT_23eea82e0 = *_DAT_23eea82e0 + 1;
    plVar10[5] = (longlong)plVar6;
    puStack_c0 = (undefined8 *)0x23e1332a6;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      puStack_c0 = (undefined8 *)0x23e1332b9;
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined8 *)(param_1 + 0x60);
      plVar6 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)*(undefined8 *)(param_1 + 0x68);
      uVar15 = 0xa3;
      goto LAB_23e133573;
    }
  }
  else {
    if (plVar10 == (longlong *)0x0) {
      puStack_c0 = (undefined8 *)0x23e133841;
      plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
    }
    else {
      lVar12 = plVar10[3];
      *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
      *(longlong *)(lVar7 + 0xe28) = lVar12;
      *plVar10 = 1;
    }
    pcVar16 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar10 + 4) = (undefined1  [16])0x0;
    lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
    lVar12 = plVar10[-1];
    puVar17 = *(undefined8 **)(lVar7 + 8);
    *puVar17 = plVar10 + -2;
    plVar10[-2] = lVar7;
    plVar10[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar7 + 8) = plVar10 + -2;
    plVar9 = DAT_23ed6a4c0;
    *plVar6 = *plVar6 + 1;
    plVar10[3] = (longlong)plVar6;
    uVar18 = DAT_23ed6cd28;
    if (plVar9 == (longlong *)0x0) {
      puStack_c0 = (undefined8 *)0x23e13397f;
      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar9 == (longlong *)0x0) goto LAB_23e133a70;
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a4c0 = plVar9;
    }
    uStack_60 = uVar18;
    puStack_c0 = (undefined8 *)0x23e1334cf;
    lVar7 = FUN_23e94ed00(param_1,plVar9,&local_68);
    if (lVar7 == 0) {
      local_78 = *(undefined8 *)(param_1 + 0x60);
      plVar6 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar15 = 0x9f;
      local_80 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar10 = *plVar10 + -1;
      lVar7 = *plVar10;
      goto joined_r0x00023e1338af;
    }
    plVar10[4] = lVar7;
    plVar6 = _DAT_23eea82d8;
    *_DAT_23eea82d8 = *_DAT_23eea82d8 + 1;
    plVar10[5] = (longlong)plVar6;
    puStack_c0 = (undefined8 *)0x23e1334fb;
    plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      puStack_c0 = (undefined8 *)0x23e13350e;
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined8 *)(param_1 + 0x60);
      plVar6 = *(longlong **)(param_1 + 0x70);
      uVar15 = 0x9d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)*(undefined8 *)(param_1 + 0x68);
      goto LAB_23e133573;
    }
  }
  puStack_c0 = (undefined8 *)0x23e1332d1;
  local_80 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23eea8268);
  if (local_80 != (longlong *)0x0) {
    *(undefined4 *)(plVar14 + 5) = 0xa4;
    puStack_c0 = (undefined8 *)0x23e1332fb;
    plVar6 = (longlong *)FUN_23e915840(param_1,plVar11,DAT_23eea8220,plVar8);
    plVar10 = local_80;
    if (plVar6 == (longlong *)0x0) {
      local_78 = *(undefined8 *)(param_1 + 0x60);
      plVar6 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar9 = *(longlong **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *local_80 = *local_80 + -1;
      uVar15 = 0xa4;
      if (*local_80 == 0) {
        plVar1 = local_80 + 1;
        local_70 = (longlong *)CONCAT44(local_70._4_4_,0xa4);
        puStack_c0 = (undefined8 *)0x23e133a13;
        local_80 = plVar9;
        (**(code **)(*plVar1 + 0x30))(plVar10);
        plVar9 = local_80;
        uVar15 = (undefined4)local_70;
      }
      goto LAB_23e133573;
    }
    *(undefined4 *)(plVar14 + 5) = 0xa4;
    puStack_c0 = (undefined8 *)0x23e133326;
    plVar9 = (longlong *)FUN_23e914090(param_1,local_80,plVar6);
    *local_80 = *local_80 + -1;
    if (*local_80 == 0) {
      puStack_c0 = (undefined8 *)0x23e13333e;
      (**(code **)(local_80[1] + 0x30))(local_80);
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      puStack_c0 = (undefined8 *)0x23e13334f;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        puStack_c0 = (undefined8 *)0x23e133368;
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar6 = *(longlong **)(lVar7 + 0x28);
      plVar14 = (longlong *)plVar6[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
      *(undefined4 *)(plVar6 + 8) = 0xffffffff;
      if (plVar14 != (longlong *)0x0) {
        plVar6[2] = 0;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          puStack_c0 = (undefined8 *)0x23e133877;
          (**(code **)(plVar14[1] + 0x30))();
        }
      }
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        puStack_c0 = (undefined8 *)0x23e1333ae;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      plVar6[0xf] = 0;
      pcVar16 = _Py_NoneStruct_exref;
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        puStack_c0 = (undefined8 *)0x23e1333d5;
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
LAB_23e133138:
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        puStack_c0 = (undefined8 *)0x23e133148;
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 == 0) {
        puStack_c0 = (undefined8 *)0x23e13315a;
        (**(code **)(plVar2[1] + 0x30))(plVar2);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        puStack_c0 = (undefined8 *)0x23e13316b;
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        return pcVar16;
      }
      return pcVar16;
    }
  }
  local_78 = *(undefined8 *)(param_1 + 0x60);
  plVar6 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar9 = (longlong *)*(undefined8 *)(param_1 + 0x68);
  uVar15 = 0xa4;
LAB_23e133573:
  local_80 = plVar9;
  plVar9 = DAT_23ed6a4f8;
  if (plVar6 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      local_70 = (longlong *)CONCAT44(local_70._4_4_,uVar15);
      puStack_c0 = (undefined8 *)0x23e133a30;
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      uVar15 = (undefined4)local_70;
    }
    else {
      plVar6 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar16 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar14;
    *plVar14 = *plVar14 + 1;
    lVar7 = *(longlong *)(pcVar16 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar15;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar12 = plVar9[-1];
    puVar17 = *(undefined8 **)(lVar7 + 8);
    *puVar17 = plVar9 + -2;
    plVar9[-2] = lVar7;
    plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
    *(longlong **)(lVar7 + 8) = plVar9 + -2;
    plVar10 = plVar9;
  }
  else {
    plVar10 = plVar6;
    if ((longlong *)plVar6[3] != plVar14) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        local_70 = (longlong *)CONCAT44(local_70._4_4_,uVar15);
        puStack_c0 = (undefined8 *)0x23e133958;
        plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar15 = (undefined4)local_70;
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar9[3] = (longlong)plVar14;
      *plVar14 = *plVar14 + 1;
      *(undefined4 *)((longlong)plVar9 + 0x24) = uVar15;
      pcVar16 = _PyRuntime_exref;
      *(undefined4 *)(plVar9 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
      lVar12 = plVar9[-1];
      puVar17 = *(undefined8 **)(lVar7 + 8);
      *puVar17 = plVar9 + -2;
      plVar9[-2] = lVar7;
      plVar9[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar17;
      lVar12 = *plVar6;
      *(longlong **)(lVar7 + 8) = plVar9 + -2;
      plVar9[2] = (longlong)plVar6;
      plVar10 = plVar9;
      if (lVar12 == 0) {
        puStack_c0 = (undefined8 *)0x23e133620;
        local_70 = plVar9;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
        plVar10 = local_70;
      }
    }
  }
  puStack_c0 = (undefined8 *)0x23e133647;
  local_98 = plVar13;
  local_90 = plVar8;
  FUN_23e8bba40(plVar14,&DAT_23ec5a149,plVar11,plVar2);
  if (_DAT_23eeaad58 == plVar14) {
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      puStack_c0 = (undefined8 *)0x23e133720;
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    _DAT_23eeaad58 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar7 + 0x28);
  plVar14 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      puStack_c0 = (undefined8 *)0x23e13368d;
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    puStack_c0 = (undefined8 *)0x23e13369d;
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    puStack_c0 = (undefined8 *)0x23e1336ba;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    puStack_c0 = (undefined8 *)0x23e1336ca;
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    puStack_c0 = (undefined8 *)0x23e1336dc;
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    puStack_c0 = (undefined8 *)0x23e1336ed;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  puStack_c0 = (undefined8 *)0x23e133702;
  FUN_23a33aa70(param_1,local_78,local_80,plVar10);
  return (code *)0x0;
}
