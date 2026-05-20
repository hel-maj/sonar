/* ===== 23e89c9d0 workers.fishing.trigger_monitor:220 ===== */
/* ghidra_name=FUN_23e89c9d0 entry=23e89c9d0 size=3143 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e89c9d0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong lVar18;
  code *pcVar19;
  undefined4 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar11 = _DAT_23eede490;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plStack_68 = (longlong *)0x0;
  plVar3 = (longlong *)param_3[2];
  auStack_78 = (undefined1  [16])0x0;
  if (_DAT_23eede490 == (longlong *)0x0) {
LAB_23e89ca46:
    _DAT_23eede490 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede488,DAT_23eede5a0,0x38);
  }
  else {
    lVar18 = *_DAT_23eede490;
    if (1 < lVar18) {
      *_DAT_23eede490 = lVar18 + -1;
      goto LAB_23e89ca46;
    }
    if (_DAT_23eede490[2] != 0) {
      *_DAT_23eede490 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e89ca46;
    }
  }
  plVar7 = _DAT_23eede490;
  lVar18 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eede490 + 9;
  lVar4 = *(longlong *)(lVar18 + 8);
  _DAT_23eede490[0xf] = lVar4;
  *(longlong **)(lVar18 + 8) = plVar11;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  plVar11 = (longlong *)FUN_23a388310(plVar3);
  if (plVar11 == (longlong *)0x0) {
    uVar21 = *(undefined8 *)(param_1 + 0x60);
    uVar22 = *(undefined8 *)(param_1 + 0x68);
    plVar16 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    plVar12 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
    if ((plVar12 == (longlong *)0x0) &&
       (plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,4), plVar12 == (longlong *)0x0)) {
      plVar15 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
    }
    else {
      plVar13 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
      if ((plVar13 == (longlong *)0x0) &&
         (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,4), plVar13 == (longlong *)0x0))
      {
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
      }
      else {
        plVar14 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
        if ((plVar14 == (longlong *)0x0) &&
           (plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,2,4), plVar14 == (longlong *)0x0)
           ) {
          plVar15 = (longlong *)0x0;
        }
        else {
          plVar15 = (longlong *)(**(code **)(plVar11[1] + 0xe0))(plVar11);
          if (((plVar15 != (longlong *)0x0) ||
              (plVar15 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,3,4),
              plVar15 != (longlong *)0x0)) &&
             (cVar9 = FUN_23a3884a0(param_1,auStack_78,plVar11,4), cVar9 != '\0')) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            plVar11 = (longlong *)FUN_23e8c09e0(plVar13,plVar15);
            if (plVar11 == (longlong *)0x0) goto LAB_23e89d500;
            plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedbff8);
            if (plVar16 == (longlong *)0x0) {
LAB_23e89d2d0:
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar20 = 0xe0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar11 = *plVar11 + -1;
              lVar18 = *plVar11;
            }
            else {
              plVar17 = (longlong *)FUN_23a388650(param_1,plVar16,DAT_23ed6ccf0,0);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (plVar17 == (longlong *)0x0) goto LAB_23e89d2d0;
              iVar10 = FUN_23e97dbc0(plVar11,plVar17);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              if (iVar10 == -1) {
LAB_23e89d500:
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                uVar20 = 0xe0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e89cfee;
              }
              if (iVar10 == 1) {
LAB_23e89d3f0:
                pcVar19 = _Py_NoneStruct_exref;
                *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
LAB_23e89d3fb:
                lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar11 = *(longlong **)(lVar18 + 0x28);
                plVar7 = (longlong *)plVar11[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
                *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                if (plVar7 != (longlong *)0x0) {
                  plVar11[2] = 0;
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    (**(code **)(plVar7[1] + 0x30))();
                  }
                }
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                plVar11[0xf] = 0;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                lVar18 = *plVar1;
                *plVar1 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                }
                lVar18 = *plVar2;
                *plVar2 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                }
                lVar18 = *plVar3;
                *plVar3 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                  return pcVar19;
                }
                return pcVar19;
              }
              plVar11 = (longlong *)FUN_23e8c09e0(plVar12,plVar14);
              if (plVar11 == (longlong *)0x0) goto LAB_23e89d500;
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedbff8);
              if (plVar16 == (longlong *)0x0) goto LAB_23e89d2d0;
              plVar17 = (longlong *)FUN_23a388650(param_1,plVar16,DAT_23ed6ccf8,1);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (plVar17 == (longlong *)0x0) goto LAB_23e89d2d0;
              iVar10 = FUN_23e97dbc0(plVar11,plVar17);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              if (iVar10 == -1) goto LAB_23e89d500;
              if (iVar10 == 1) goto LAB_23e89d3f0;
              plVar11 = (longlong *)FUN_23e8c09e0(plVar13,plVar15);
              pcVar19 = _Py_NoneStruct_exref;
              if (plVar11 == (longlong *)0x0) {
LAB_23e89ce77:
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                uVar20 = 0xe3;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e89cfee;
              }
              lVar18 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar13,plVar11,
                                     _Py_NoneStruct_exref);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              lVar4 = *(longlong *)(param_1 + 0x10);
              plVar11 = *(longlong **)(lVar4 + 0xe20);
              if (plVar11 == (longlong *)0x0) {
                plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar5 = plVar11[3];
                *(int *)(lVar4 + 0xebc) = *(int *)(lVar4 + 0xebc) + -1;
                *(longlong *)(lVar4 + 0xe20) = lVar5;
                *plVar11 = 1;
              }
              pcVar8 = _PyRuntime_exref;
              plVar11[4] = 0;
              lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar8 + 0x1f8) + 0x10) + 0x2e8);
              lVar5 = plVar11[-1];
              puVar6 = *(undefined8 **)(lVar4 + 8);
              *puVar6 = plVar11 + -2;
              plVar11[-2] = lVar4;
              plVar11[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar6;
              *(longlong **)(lVar4 + 8) = plVar11 + -2;
              plVar11[3] = lVar18;
              plVar16 = (longlong *)FUN_23e8c09e0(plVar12,plVar14);
              if (plVar16 != (longlong *)0x0) {
                lVar18 = FUN_23e8d69f0(*(undefined8 *)(param_1 + 0x10),plVar12,plVar16,pcVar19);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                plVar11[4] = lVar18;
                pcVar19 = (code *)FUN_23a38cc10(param_1,plVar2,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (pcVar19 != (code *)0x0) goto LAB_23e89d3fb;
                goto LAB_23e89ce77;
              }
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar20 = 0xe3;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar11 = *plVar11 + -1;
              lVar18 = *plVar11;
            }
            if (lVar18 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            goto LAB_23e89cfee;
          }
        }
      }
    }
    plVar16 = plStack_68;
    uVar21 = auStack_78._0_8_;
    uVar22 = auStack_78._8_8_;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plStack_68 = (longlong *)0x0;
    auStack_78 = (undefined1  [16])0x0;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
  }
  plVar15 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  auStack_78._8_8_ = uVar22;
  auStack_78._0_8_ = uVar21;
  uVar20 = 0xde;
  plVar12 = (longlong *)0x0;
  plStack_68 = plVar16;
LAB_23e89cfee:
  plVar16 = plStack_68;
  plVar11 = DAT_23ed6a4f8;
  if (plStack_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar19 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar18 = *(longlong *)(pcVar19 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar20;
    lVar18 = *(longlong *)(lVar18 + 0x10);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar18 = *(longlong *)(lVar18 + 0x2e8);
    lVar4 = plVar11[-1];
    puVar6 = *(undefined8 **)(lVar18 + 8);
    *puVar6 = plVar11 + -2;
    plVar11[-2] = lVar18;
    plVar11[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar18 + 8) = plVar11 + -2;
    plVar17 = plVar11;
  }
  else {
    plVar17 = plStack_68;
    if ((longlong *)plStack_68[3] != plVar7) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar17 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar19 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      lVar18 = *(longlong *)(pcVar19 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar20;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar18 = *(longlong *)(*(longlong *)(lVar18 + 0x10) + 0x2e8);
      lVar4 = plVar11[-1];
      puVar6 = *(undefined8 **)(lVar18 + 8);
      *puVar6 = plVar11 + -2;
      plVar11[-2] = lVar18;
      plVar11[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
      lVar4 = *plVar16;
      *(longlong **)(lVar18 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar16;
      plVar17 = plVar11;
      if (lVar4 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
    }
  }
  plStack_68 = plVar17;
  FUN_23e8bba40(plVar7,"ooooooo",plVar1,plVar2,plVar3,plVar12,plVar13,plVar14,plVar15);
  if (_DAT_23eede490 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eede490 = (longlong *)0x0;
  }
  lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar11 = *(longlong **)(lVar18 + 0x28);
  plVar7 = (longlong *)plVar11[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
  *(undefined4 *)(plVar11 + 8) = 0xffffffff;
  if (plVar7 != (longlong *)0x0) {
    plVar11[2] = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))();
    }
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar7 = plStack_68;
  plVar11[0xf] = 0;
  uVar22 = auStack_78._8_8_;
  uVar21 = auStack_78._0_8_;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  lVar18 = *plVar1;
  *plVar1 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar18 = *plVar2;
  *plVar2 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  lVar18 = *plVar3;
  *plVar3 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,uVar21,uVar22,plVar7);
  return (code *)0x0;
}
