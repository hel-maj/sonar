/* ===== 23e27b400 ui.fish_settings_dialog:c1211 ===== */
/* ghidra_name=FUN_23e27b400 entry=23e27b400 size=3164 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e27b400(longlong param_1,undefined8 param_2,longlong *param_3)

{
  code *pcVar1;
  undefined8 *puVar2;
  char cVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  int iVar16;
  longlong lVar17;
  undefined4 uVar18;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  undefined4 uVar19;
  
  lVar17 = DAT_23ed6cce8;
  param_3 = (longlong *)*param_3;
  lVar12 = *(longlong *)(param_1 + 0x10);
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  iVar16 = *(int *)(lVar12 + 0x1410);
  plVar7 = *(longlong **)(DAT_23ed6cce8 + 0x20);
  *plVar7 = *plVar7 + 1;
  if (iVar16 == 0) {
    plVar14 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
    plVar7 = *(longlong **)(lVar17 + 0x20);
  }
  else {
    iVar16 = iVar16 + -1;
    *(int *)(lVar12 + 0x1410) = iVar16;
    plVar14 = *(longlong **)(lVar12 + 0x1190 + (longlong)iVar16 * 8);
    *plVar14 = 1;
  }
  plVar4 = _DAT_23eeb06e8;
  lVar12 = *(longlong *)(lVar17 + 0x28);
  plVar14[4] = (longlong)plVar7;
  plVar14[5] = lVar12;
  plVar14[2] = 0;
  plVar14[3] = 1;
  if (plVar4 == (longlong *)0x0) {
LAB_23e27b4c0:
    plVar4 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb07c0,DAT_23eeb0770,0x20);
    _DAT_23eeb06e8 = plVar4;
  }
  else {
    lVar12 = *plVar4;
    if (1 < lVar12) {
      *plVar4 = lVar12 + -1;
      goto LAB_23e27b4c0;
    }
    if (plVar4[2] != 0) {
      *plVar4 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
      }
      goto LAB_23e27b4c0;
    }
  }
  lVar12 = *(longlong *)(param_1 + 0x38);
  lVar17 = *(longlong *)(lVar12 + 8);
  plVar4[0xf] = lVar17;
  *(longlong **)(lVar12 + 8) = plVar4 + 9;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar20 = DAT_23eeaf440;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar5 = (longlong *)FUN_23e8bc2f0(param_3,uVar20);
  plVar7 = (longlong *)0x0;
  if (plVar5 == (longlong *)0x0) goto LAB_23e27bbe4;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar5,_DAT_23eeaf638);
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
    if (plVar6 != (longlong *)0x0) goto LAB_23e27b586;
LAB_23e27bae3:
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar7 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0x100;
    uVar18 = 0x100;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plStack_68 == (longlong *)0x0) {
      plStack_68 = (longlong *)0x0;
LAB_23e27bb20:
      plVar5 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar5 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar1 = _PyRuntime_exref;
      plVar5[2] = 0;
      plVar5[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar12 = *(longlong *)(pcVar1 + 0x1f8);
      *(undefined4 *)(plVar5 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(lVar12 + 0x10);
      *(undefined4 *)((longlong)plVar5 + 0x24) = uVar19;
      lVar12 = *(longlong *)(lVar12 + 0x2e8);
      lVar17 = plVar5[-1];
      puVar2 = *(undefined8 **)(lVar12 + 8);
      *puVar2 = plVar5 + -2;
      plVar5[-2] = lVar12;
      plVar5[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar12 + 8) = plVar5 + -2;
      if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
        (**(code **)(plStack_68[1] + 0x30))(plStack_68);
      }
      goto LAB_23e27b976;
    }
  }
  else {
    if (plVar6 == (longlong *)0x0) goto LAB_23e27bae3;
LAB_23e27b586:
    *(undefined4 *)(plVar4 + 5) = 0x100;
    plVar7 = (longlong *)FUN_23e91a870(param_1,plVar6);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
      if (plVar7 != (longlong *)0x0) goto LAB_23e27b5b0;
LAB_23e27bbe4:
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      plVar6 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0x100;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else {
      if (plVar7 == (longlong *)0x0) goto LAB_23e27bbe4;
LAB_23e27b5b0:
      plVar5 = (longlong *)FUN_23ebf7180(plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      plVar6 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      if (plVar5 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        uVar18 = 0x100;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        do {
          pcVar1 = *(code **)(plVar5[1] + 0xe0);
          if (pcVar1 == (code *)0x0) {
            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                         *(undefined8 *)(plVar5[1] + 0x18));
LAB_23e27bcc0:
            cVar3 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar3 != '\0') {
              if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              lVar12 = *plVar5;
              *plVar5 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                (**(code **)(plVar5[1] + 0x30))(plVar5);
              }
              *plVar14 = *plVar14 + 1;
              lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar4 = *(longlong **)(lVar12 + 0x28);
              plVar5 = (longlong *)plVar4[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
              *(undefined4 *)(plVar4 + 8) = 0xffffffff;
              if (plVar5 != (longlong *)0x0) {
                plVar4[2] = 0;
                *plVar5 = *plVar5 + -1;
                if (*plVar5 == 0) {
                  (**(code **)(plVar5[1] + 0x30))();
                }
              }
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))(plVar4);
              }
              plVar4[0xf] = 0;
              lVar12 = *plVar14;
              *plVar14 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              lVar12 = *param_3;
              *param_3 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                (**(code **)(param_3[1] + 0x30))(param_3);
                return plVar14;
              }
              return plVar14;
            }
            lVar12 = *(longlong *)(param_1 + 0x60);
            uVar20 = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            plStack_68 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_78 = (undefined1  [16])0x0;
            if (plVar15 != (longlong *)0x0) goto LAB_23e27b87f;
            uVar18 = 0x100;
            goto LAB_23e27b890;
          }
          plVar8 = (longlong *)(*pcVar1)(plVar5);
          if (plVar8 == (longlong *)0x0) goto LAB_23e27bcc0;
          if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          plVar9 = (longlong *)FUN_23a388310(plVar8);
          plVar15 = plVar8;
          if (plVar9 == (longlong *)0x0) {
            lVar12 = *(longlong *)(param_1 + 0x60);
            uVar20 = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e27beb7:
            *plVar8 = *plVar8 + -1;
            lVar17 = *plVar8;
            goto joined_r0x00023e27bed3;
          }
          plVar10 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
          if ((plVar10 == (longlong *)0x0) &&
             (plVar10 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,2),
             plVar10 == (longlong *)0x0)) {
            plVar11 = (longlong *)0x0;
            lVar17 = *plVar9;
LAB_23e27be2d:
            plVar13 = plStack_68;
            lVar12 = auStack_78._0_8_;
            uVar20 = auStack_78._8_8_;
            auStack_78 = (undefined1  [16])0x0;
            plStack_68 = (longlong *)0x0;
            *plVar9 = lVar17 + -1;
            if (lVar17 + -1 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [16])0x0;
            if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            goto LAB_23e27beb7;
          }
          plVar11 = (longlong *)(**(code **)(plVar9[1] + 0xe0))(plVar9);
          if ((plVar11 == (longlong *)0x0) &&
             (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,2),
             plVar11 == (longlong *)0x0)) {
            lVar17 = *plVar9;
            goto LAB_23e27be2d;
          }
          cVar3 = FUN_23a3884a0(param_1,auStack_78,plVar9,2);
          lVar17 = *plVar9;
          if (cVar3 == '\0') goto LAB_23e27be2d;
          *plVar9 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          lVar12 = *plVar10;
          *plVar10 = lVar12 + 1;
          if (plVar7 != (longlong *)0x0) {
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            lVar12 = *plVar10 + -1;
          }
          *plVar10 = lVar12;
          if (lVar12 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          lVar12 = *plVar11;
          *plVar11 = lVar12 + 1;
          if (plVar6 != (longlong *)0x0) {
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            lVar12 = *plVar11 + -1;
          }
          *plVar11 = lVar12;
          if (lVar12 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          uVar20 = _DAT_23eeaf640;
          *(undefined4 *)(plVar4 + 5) = 0x101;
          plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar11,uVar20);
          plVar6 = plVar11;
          plVar7 = plVar10;
          if (plVar13 == (longlong *)0x0) {
LAB_23e27bf90:
            lVar12 = *(longlong *)(param_1 + 0x60);
            uVar20 = *(undefined8 *)(param_1 + 0x68);
            plVar13 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uVar18 = 0x101;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar8 = *plVar8 + -1;
            lVar17 = *plVar8;
            goto joined_r0x00023e27bfcc;
          }
          iVar16 = PyDict_SetItem(plVar14,plVar10);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (iVar16 != 0) goto LAB_23e27bf90;
          lVar17 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar17 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar17 + 0x78) != 0)) && (iVar16 = Py_MakePendingCalls(), iVar16 < 0)) &&
             (lVar12 = *(longlong *)(param_1 + 0x60), lVar12 != 0)) goto LAB_23e27b849;
          if (*(int *)(lVar17 + 0x68) == 0) {
            plVar8 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar8 = *(longlong **)(param_1 + 0x90);
          }
        } while (plVar8 == (longlong *)0x0);
        plVar13 = *(longlong **)(param_1 + 0x60);
        plVar9 = *(longlong **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x90) = 0;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar8;
        *plVar8 = *plVar8 + 1;
        *(undefined8 *)(param_1 + 0x68) = 0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        lVar12 = *(longlong *)(param_1 + 0x60);
LAB_23e27b849:
        plVar13 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar20 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e27b87f:
        *plVar15 = *plVar15 + -1;
        lVar17 = *plVar15;
joined_r0x00023e27bed3:
        uVar18 = 0x100;
joined_r0x00023e27bfcc:
        auStack_78 = (undefined1  [16])0x0;
        plStack_68 = (longlong *)0x0;
        if (lVar17 == 0) {
          plStack_68 = (longlong *)0x0;
          auStack_78 = (undefined1  [16])0x0;
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
LAB_23e27b890:
        lVar17 = *plVar5;
        *plVar5 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        auStack_78._8_8_ = uVar20;
        auStack_78._0_8_ = lVar12;
        plStack_68 = plVar13;
      }
    }
    uVar19 = uVar18;
    if (plStack_68 == (longlong *)0x0) goto LAB_23e27bb20;
  }
  plVar5 = plStack_68;
  plVar15 = DAT_23ed6a4f8;
  if ((longlong *)plStack_68[3] != plVar4) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar1 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar12 = *(longlong *)(pcVar1 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar18;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar17 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar12 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar12;
    plVar15[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar12 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    plVar5 = plVar15;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
LAB_23e27b976:
  plStack_68 = plVar5;
  plVar5 = plVar7;
  plVar15 = plVar6;
  FUN_23e8bba40(plVar4,&DAT_23ec5b359,param_3,plVar14,plVar7,plVar6);
  if (_DAT_23eeb06e8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb06e8 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar12 + 0x28);
  plVar8 = (longlong *)plVar4[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
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
    plVar4[0xf] = 0;
    plVar4 = plStack_68;
    uVar20 = auStack_78._0_8_;
    uVar21 = auStack_78._8_8_;
  }
  else {
    plVar4[0xf] = 0;
    plVar4 = plStack_68;
    uVar20 = auStack_78._0_8_;
    uVar21 = auStack_78._8_8_;
  }
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  lVar12 = *plVar14;
  *plVar14 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  lVar12 = *param_3;
  *param_3 = lVar12 + -1;
  plStack_68 = plVar4;
  auStack_78._0_8_ = uVar20;
  auStack_78._8_8_ = uVar21;
  if (lVar12 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,plStack_68,plVar5,plVar15,lVar12);
  return (longlong *)0x0;
}
