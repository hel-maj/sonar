/* ===== 23e716990 workers.fishing.fish_recognition:218 ===== */
/* ghidra_name=FUN_23e716990 entry=23e716990 size=6511 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e716990(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  code *pcVar18;
  undefined4 uVar19;
  longlong *plVar20;
  undefined8 uVar21;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d0;
  longlong *plStack_c0;
  code *pcStack_b8;
  undefined1 auStack_98 [16];
  longlong *aplStack_88 [2];
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar8 = _DAT_23eedb078;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  aplStack_88[0] = (longlong *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
  plStack_c0 = DAT_23ed6cd08;
  *DAT_23ed6cd08 = *DAT_23ed6cd08 + 1;
  if (plVar8 == (longlong *)0x0) {
LAB_23e716a20:
    plVar8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedb070,DAT_23eedb148,0x48);
    _DAT_23eedb078 = plVar8;
  }
  else {
    lVar17 = *plVar8;
    if (1 < lVar17) {
      *plVar8 = lVar17 + -1;
      goto LAB_23e716a20;
    }
    if (plVar8[2] != 0) {
      *plVar8 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e716a20;
    }
  }
  lVar17 = *(longlong *)(param_1 + 0x38);
  lVar3 = *(longlong *)(lVar17 + 8);
  plVar8[0xf] = lVar3;
  *(longlong **)(lVar17 + 8) = plVar8 + 9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar8[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar8[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar8 = *plVar8 + 1;
  uVar21 = DAT_23eed9eb0;
  *(undefined4 *)(plVar8 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar21);
  pcStack_b8 = _Py_NoneStruct_exref;
  if (plVar9 == (longlong *)0x0) {
    pcVar18 = *(code **)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plStack_e0 = (longlong *)0x0;
    uVar19 = 0xe3;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_f0 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar12 = (longlong *)0x0;
    uVar21 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23e7170e6;
  }
  plVar10 = (longlong *)FUN_23ebf7180(plVar9);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar10 == (longlong *)0x0) {
    pcVar18 = *(code **)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    uVar19 = 0xe3;
    pcStack_b8 = _Py_NoneStruct_exref;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plStack_e0 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar21 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23e7170e6;
  }
  if (plVar1 == (longlong *)0x0) {
    lVar17 = plVar10[1];
    if (*(code **)(lVar17 + 0xe0) != (code *)0x0) {
      plVar11 = (longlong *)(**(code **)(lVar17 + 0xe0))(plVar10);
      if (plVar11 == (longlong *)0x0) {
        cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
        if (cVar6 == '\0') {
          plVar9 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar18 = *(code **)(param_1 + 0x60);
          uVar21 = *(undefined8 *)(param_1 + 0x68);
          uVar19 = 0xe3;
          pcStack_b8 = _Py_NoneStruct_exref;
          aplStack_88[0] = (longlong *)0x0;
          plStack_e0 = (longlong *)0x0;
          plStack_f0 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          plStack_d0 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          auStack_98 = (undefined1  [16])0x0;
          plVar12 = plVar11;
          goto LAB_23e7170a0;
        }
        plVar12 = (longlong *)0x0;
        plStack_d0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        plStack_e8 = (longlong *)0x0;
        lVar17 = *plVar10;
        *plVar10 = lVar17 + -1;
        pcStack_b8 = _Py_NoneStruct_exref;
        plStack_f0 = (longlong *)0x0;
        if (lVar17 + -1 == 0) goto LAB_23e717579;
LAB_23e717592:
        lVar17 = *(longlong *)(param_1 + 0x10);
        plVar9 = *(longlong **)(lVar17 + 0xe20);
        if (plVar9 == (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar3 = plVar9[3];
          *(int *)(lVar17 + 0xebc) = *(int *)(lVar17 + 0xebc) + -1;
          *(longlong *)(lVar17 + 0xe20) = lVar3;
          *plVar9 = 1;
        }
        pcVar18 = _PyRuntime_exref;
        plVar9[4] = 0;
        lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = plVar9[-1];
        puVar4 = *(undefined8 **)(lVar17 + 8);
        *puVar4 = plVar9 + -2;
        plVar9[-2] = lVar17;
        plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar17 + 8) = plVar9 + -2;
        *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + 1;
        plVar9[3] = (longlong)pcStack_b8;
        if (plStack_c0 != (longlong *)0x0) {
          *plStack_c0 = *plStack_c0 + 1;
          plVar9[4] = (longlong)plStack_c0;
          lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar8 = *(longlong **)(lVar17 + 0x28);
          plVar10 = (longlong *)plVar8[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
          *(undefined4 *)(plVar8 + 8) = 0xffffffff;
          if (plVar10 != (longlong *)0x0) {
            plVar8[2] = 0;
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))();
            }
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar8[0xf] = 0;
          lVar17 = *(longlong *)pcStack_b8;
          *(longlong *)pcStack_b8 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))(pcStack_b8);
          }
          lVar17 = *plStack_c0;
          *plStack_c0 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
          }
          if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if ((plStack_d0 != (longlong *)0x0) &&
             (lVar17 = *plStack_d0, *plStack_d0 = lVar17 + -1, lVar17 + -1 == 0)) {
            (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
          }
          if ((plStack_e8 != (longlong *)0x0) &&
             (lVar17 = *plStack_e8, *plStack_e8 = lVar17 + -1, lVar17 + -1 == 0)) {
            (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
          }
          if ((plStack_f0 != (longlong *)0x0) &&
             (lVar17 = *plStack_f0, *plStack_f0 = lVar17 + -1, lVar17 + -1 == 0)) {
            (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
          }
          if ((plStack_e0 != (longlong *)0x0) &&
             (lVar17 = *plStack_e0, *plStack_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
            (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
          }
          lVar17 = *plVar1;
          *plVar1 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          lVar17 = *plVar2;
          *plVar2 = lVar17 + -1;
          if (lVar17 + -1 != 0) {
            return plVar9;
          }
          (**(code **)(plVar2[1] + 0x30))(plVar2);
          return plVar9;
        }
        auStack_98._8_8_ =
             PyUnicode_FromFormat
                       ("cannot access local variable \'%U\' where it is not associated with a value"
                        ,_DAT_23eeda060);
        auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
        aplStack_88[0] = (longlong *)0x0;
        if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,aplStack_88);
        }
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          uVar19 = 0xec;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
          plVar9 = aplStack_88[0];
          pcVar18 = (code *)auStack_98._0_8_;
          uVar21 = auStack_98._8_8_;
        }
        else {
          uVar19 = 0xec;
          plVar9 = aplStack_88[0];
          pcVar18 = (code *)auStack_98._0_8_;
          uVar21 = auStack_98._8_8_;
        }
        goto LAB_23e7170e6;
      }
      *plVar11 = *plVar11 + 1;
      auStack_98._8_8_ =
           PyUnicode_FromFormat
                     ("cannot access local variable \'%U\' where it is not associated with a value",
                      DAT_23eed9d30);
      auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
      *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
      aplStack_88[0] = (longlong *)0x0;
      if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
        FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,aplStack_88);
      }
      uVar19 = 0xe4;
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
      pcStack_b8 = _Py_NoneStruct_exref;
      plStack_e0 = (longlong *)0x0;
      plStack_f0 = (longlong *)0x0;
      plStack_e8 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x0;
      plVar9 = aplStack_88[0];
      pcVar18 = (code *)auStack_98._0_8_;
      uVar21 = auStack_98._8_8_;
      goto LAB_23e717080;
    }
    pcStack_b8 = _Py_NoneStruct_exref;
    plVar12 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_d0 = (longlong *)0x0;
LAB_23e717513:
    PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                 *(undefined8 *)(lVar17 + 0x18));
LAB_23e71752e:
    cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
    if (cVar6 != '\0') {
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar17 = *plVar10;
      *plVar10 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
LAB_23e717579:
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (pcStack_b8 == (code *)0x0) {
        auStack_98._8_8_ =
             PyUnicode_FromFormat
                       ("cannot access local variable \'%U\' where it is not associated with a value"
                        ,_DAT_23eeda068);
        auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
        aplStack_88[0] = (longlong *)0x0;
        if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,aplStack_88);
        }
        uVar19 = 0xec;
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
        plVar9 = aplStack_88[0];
        pcVar18 = (code *)auStack_98._0_8_;
        uVar21 = auStack_98._8_8_;
        goto LAB_23e7170e6;
      }
      goto LAB_23e717592;
    }
    plVar9 = *(longlong **)(param_1 + 0x70);
    pcVar18 = *(code **)(param_1 + 0x60);
    uVar21 = *(undefined8 *)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x70) = 0;
    aplStack_88[0] = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    auStack_98 = (undefined1  [16])0x0;
    if (plVar12 != (longlong *)0x0) {
      uVar19 = 0xe3;
      plVar11 = plVar12;
      goto LAB_23e717080;
    }
    uVar19 = 0xe3;
    plVar12 = (longlong *)0x0;
  }
  else {
    plStack_e0 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    pcStack_b8 = _Py_NoneStruct_exref;
    plStack_e8 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    plVar20 = (longlong *)0x0;
    do {
      lVar17 = plVar10[1];
      plStack_d0 = plVar20;
      if (*(code **)(lVar17 + 0xe0) == (code *)0x0) goto LAB_23e717513;
      plVar11 = (longlong *)(**(code **)(lVar17 + 0xe0))();
      if (plVar11 == (longlong *)0x0) goto LAB_23e71752e;
      if (plVar12 == (longlong *)0x0) {
        *plVar11 = *plVar11 + 1;
      }
      else {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar11 = *plVar11 + 1;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeda050);
      if (plVar12 == (longlong *)0x0) goto LAB_23e717b40;
      if (plVar2 == (longlong *)0x0) {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        auStack_98._8_8_ =
             PyUnicode_FromFormat
                       ("cannot access local variable \'%U\' where it is not associated with a value"
                        ,_DAT_23eeda058);
        auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
        *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
        aplStack_88[0] = (longlong *)0x0;
        if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
          FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,aplStack_88);
        }
        uVar19 = 0xe5;
        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
        plVar9 = aplStack_88[0];
        pcVar18 = (code *)auStack_98._0_8_;
        uVar21 = auStack_98._8_8_;
        goto LAB_23e717080;
      }
      plVar9 = (longlong *)FUN_23a38cc10(param_1,plVar11,_DAT_23eed9fe8);
      if (plVar9 == (longlong *)0x0) {
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        aplStack_88[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar19 = 0xe5;
        *plVar12 = *plVar12 + -1;
        plVar9 = aplStack_88[0];
        pcVar18 = (code *)auStack_98._0_8_;
        uVar21 = auStack_98._8_8_;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          plVar9 = aplStack_88[0];
          pcVar18 = (code *)auStack_98._0_8_;
          uVar21 = auStack_98._8_8_;
        }
        goto LAB_23e717080;
      }
      plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed9ea8);
      if (plVar13 == (longlong *)0x0) {
        auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
        aplStack_88[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        uVar19 = 0xe5;
        plVar9 = aplStack_88[0];
        pcVar18 = (code *)auStack_98._0_8_;
        uVar21 = auStack_98._8_8_;
        goto LAB_23e717080;
      }
      *(undefined4 *)(plVar8 + 5) = 0xe4;
      plStack_78 = plVar2;
      plStack_70 = plVar9;
      plStack_68 = plVar13;
      plVar14 = (longlong *)FUN_23e956150(param_1,plVar12,&plStack_78);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      if (plVar14 == (longlong *)0x0) {
LAB_23e717b40:
        plVar9 = *(longlong **)(param_1 + 0x70);
        pcVar18 = *(code **)(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar19 = 0xe4;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar21 = *(undefined8 *)(param_1 + 0x68);
        goto LAB_23e717080;
      }
      plVar12 = (longlong *)FUN_23a388310(plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e717b40;
      plVar13 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar13 == (longlong *)0x0) &&
         (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,4), plVar13 == (longlong *)0x0))
      {
        lVar17 = *plVar12;
        plVar16 = (longlong *)0x0;
        plVar15 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
LAB_23e717823:
        plVar9 = aplStack_88[0];
        pcVar18 = (code *)auStack_98._0_8_;
        uVar21 = auStack_98._8_8_;
        auStack_98 = (undefined1  [16])0x0;
        aplStack_88[0] = (longlong *)0x0;
        *plVar12 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        aplStack_88[0] = (longlong *)0x0;
        auStack_98 = (undefined1  [16])0x0;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        uVar19 = 0xe4;
        plStack_d0 = plVar20;
        goto LAB_23e717080;
      }
      plStack_d0 = (longlong *)auStack_98;
      plVar14 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar14 == (longlong *)0x0) &&
         (plVar14 = (longlong *)FUN_23a3c1b70(param_1,plStack_d0,1,4), plVar14 == (longlong *)0x0))
      {
        lVar17 = *plVar12;
        plVar16 = (longlong *)0x0;
        plVar15 = (longlong *)0x0;
        goto LAB_23e717823;
      }
      plVar15 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar15 == (longlong *)0x0) &&
         (plVar15 = (longlong *)FUN_23a3c1b70(param_1,plStack_d0,2,4), plVar15 == (longlong *)0x0))
      {
        lVar17 = *plVar12;
        plVar16 = (longlong *)0x0;
        goto LAB_23e717823;
      }
      plVar16 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
      if ((plVar16 == (longlong *)0x0) &&
         (plVar16 = (longlong *)FUN_23a3c1b70(param_1,plStack_d0,3,4), plVar16 == (longlong *)0x0))
      {
        lVar17 = *plVar12;
        goto LAB_23e717823;
      }
      cVar6 = FUN_23a3884a0(param_1,plStack_d0,plVar12,4);
      lVar17 = *plVar12;
      if (cVar6 == '\0') goto LAB_23e717823;
      *plVar12 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar17 = *plVar13;
      *plVar13 = lVar17 + 1;
      if (plVar20 != (longlong *)0x0) {
        *plVar20 = *plVar20 + -1;
        if (*plVar20 == 0) {
          (**(code **)(plVar20[1] + 0x30))(plVar20);
          lVar17 = *plVar13 + -1;
        }
        else {
          lVar17 = *plVar13 + -1;
        }
      }
      *plVar13 = lVar17;
      if (lVar17 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      lVar17 = *plVar14;
      *plVar14 = lVar17 + 1;
      if (plStack_e8 != (longlong *)0x0) {
        lVar17 = *plStack_e8;
        *plStack_e8 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
          lVar17 = *plVar14 + -1;
        }
        else {
          lVar17 = *plVar14 + -1;
        }
      }
      *plVar14 = lVar17;
      if (lVar17 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      lVar17 = *plVar15;
      *plVar15 = lVar17 + 1;
      if (plStack_f0 != (longlong *)0x0) {
        lVar17 = *plStack_f0;
        *plStack_f0 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
          lVar17 = *plVar15 + -1;
        }
        else {
          lVar17 = *plVar15 + -1;
        }
      }
      *plVar15 = lVar17;
      if (lVar17 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      lVar17 = *plVar16;
      *plVar16 = lVar17 + 1;
      if (plStack_e0 != (longlong *)0x0) {
        lVar17 = *plStack_e0;
        *plStack_e0 = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
          lVar17 = *plVar16 + -1;
        }
        else {
          lVar17 = *plVar16 + -1;
        }
      }
      *plVar16 = lVar17;
      if (lVar17 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      iVar7 = FUN_23a35f020(plVar13);
      plStack_f0 = plVar15;
      plStack_e8 = plVar14;
      plStack_e0 = plVar16;
      if (iVar7 == -1) {
LAB_23e717c50:
        aplStack_88[0] = *(longlong **)(param_1 + 0x70);
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e717c71:
        uVar19 = 0xe8;
        plVar9 = aplStack_88[0];
        pcVar18 = (code *)auStack_98._0_8_;
        uVar21 = auStack_98._8_8_;
        plStack_d0 = plVar13;
        goto LAB_23e717080;
      }
      pcVar18 = pcStack_b8;
      if (iVar7 != 0) {
        if (plStack_c0 == (longlong *)0x0) {
          auStack_98._8_8_ =
               PyUnicode_FromFormat
                         ("cannot access local variable \'%U\' where it is not associated with a value"
                          ,_DAT_23eeda060);
          auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
          *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
          aplStack_88[0] = (longlong *)0x0;
          if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
            FUN_23e91b1b0(param_1,plStack_d0,auStack_98 + 8,aplStack_88);
          }
          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
          goto LAB_23e717c71;
        }
        iVar7 = FUN_23e97dbc0(plVar16,plStack_c0);
        if (iVar7 == -1) goto LAB_23e717c50;
        if (iVar7 == 1) {
          *plVar16 = *plVar16 + 1;
          lVar17 = *plStack_c0;
          *plStack_c0 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
          }
          pcVar18 = (code *)FUN_23a38cc10(param_1,plVar11,DAT_23ed6ce48);
          plStack_c0 = plVar16;
          if (pcVar18 == (code *)0x0) {
            pcVar18 = *(code **)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            uVar19 = 0xea;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar21 = *(undefined8 *)(param_1 + 0x68);
            plStack_d0 = plVar13;
            goto LAB_23e717080;
          }
          if ((pcStack_b8 != (code *)0x0) &&
             (lVar17 = *(longlong *)pcStack_b8, *(longlong *)pcStack_b8 = lVar17 + -1,
             lVar17 + -1 == 0)) {
            (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))(pcStack_b8);
          }
        }
      }
      pcStack_b8 = pcVar18;
      lVar17 = *(longlong *)(param_1 + 0x10);
      if ((((*(int *)(*(longlong *)(lVar17 + 0x28) + 0x160) != 0) || (*(int *)(lVar17 + 0x78) != 0))
          && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)) &&
         (pcVar18 = *(code **)(param_1 + 0x60), pcVar18 != (code *)0x0)) goto LAB_23e717030;
      if (*(int *)(lVar17 + 0x68) == 0) {
        plVar9 = *(longlong **)(param_1 + 0x90);
      }
      else {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
        plVar9 = *(longlong **)(param_1 + 0x90);
      }
      plVar12 = plVar11;
      plVar20 = plVar13;
    } while (plVar9 == (longlong *)0x0);
    plVar12 = *(longlong **)(param_1 + 0x60);
    plVar20 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar14 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar9;
    *plVar9 = *plVar9 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    pcVar18 = *(code **)(param_1 + 0x60);
LAB_23e717030:
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0xe3;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar21 = *(undefined8 *)(param_1 + 0x68);
    plStack_d0 = plVar13;
LAB_23e717080:
    aplStack_88[0] = (longlong *)0x0;
    auStack_98 = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    plVar12 = plVar11;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
  }
LAB_23e7170a0:
  lVar17 = *plVar10;
  *plVar10 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
LAB_23e7170e6:
  auStack_98._8_8_ = uVar21;
  auStack_98._0_8_ = pcVar18;
  aplStack_88[0] = plVar9;
  plVar10 = aplStack_88[0];
  plVar9 = DAT_23ed6a4f8;
  if (aplStack_88[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar17 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(lVar17 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar19;
    lVar17 = *(longlong *)(lVar17 + 0x2e8);
    lVar3 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar17 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar17;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar17 + 8) = plVar9 + -2;
    plVar10 = plVar9;
    if ((aplStack_88[0] != (longlong *)0x0) &&
       (*aplStack_88[0] = *aplStack_88[0] + -1, *aplStack_88[0] == 0)) {
      (**(code **)(aplStack_88[0][1] + 0x30))(aplStack_88[0]);
    }
  }
  else if ((longlong *)aplStack_88[0][3] != plVar8) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    lVar17 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar19;
    lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
    lVar3 = plVar9[-1];
    puVar4 = *(undefined8 **)(lVar17 + 8);
    *puVar4 = plVar9 + -2;
    plVar9[-2] = lVar17;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar17 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    plVar10 = plVar9;
    if ((aplStack_88[0] != (longlong *)0x0) &&
       (*aplStack_88[0] = *aplStack_88[0] + -1, *aplStack_88[0] == 0)) {
      (**(code **)(aplStack_88[0][1] + 0x30))();
    }
  }
  aplStack_88[0] = plVar10;
  FUN_23e8bba40(plVar8,"ooooooooo",plVar1,plVar2,pcStack_b8,plStack_c0,plVar12,plStack_d0,plStack_e8
                ,plStack_f0,plStack_e0);
  if (_DAT_23eedb078 == plVar8) {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    _DAT_23eedb078 = (longlong *)0x0;
  }
  lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar17 + 0x28);
  plVar9 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar9 = aplStack_88[0];
  uVar5 = auStack_98._8_8_;
  uVar21 = auStack_98._0_8_;
  plVar8[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  aplStack_88[0] = (longlong *)0x0;
  if ((pcStack_b8 != (code *)0x0) &&
     (lVar17 = *(longlong *)pcStack_b8, *(longlong *)pcStack_b8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))(pcStack_b8);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar17 = *plStack_c0, *plStack_c0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plStack_d0 != (longlong *)0x0) &&
     (lVar17 = *plStack_d0, *plStack_d0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar17 = *plStack_e8, *plStack_e8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar17 = *plStack_f0, *plStack_f0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar17 = *plStack_e0, *plStack_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  auStack_98 = CONCAT88(uVar5,uVar21);
  lVar17 = *plVar1;
  *plVar1 = lVar17 + -1;
  aplStack_88[0] = plVar9;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar17 = *plVar2;
  *plVar2 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,aplStack_88[0]);
  return (longlong *)0x0;
}
